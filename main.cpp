#include <iostream>
#include <utility>
#include "BinaryExpressionTree.hpp"

#ifdef _WIN32
char* readline(char* notUsed)
{
  std::string out;
  std::cout << "=>";
  std::getline(std::cin, out);
  return out.c_str();
}

void add_history(char* notUsed) {}
#else

#include <readline/history.h>
#include <readline/readline.h>
#endif
static std::map<std::string, std::pair<std::string, std::string>> vars;
double resolveDouble(std::string input)
{
	BinaryExpressionTree Tree;
	Tree.fromInfix(input);
	return Tree.evaluateDouble(vars);
}

long resolveInteger(std::string input)
{
	BinaryExpressionTree Tree;
	Tree.fromInfix(input);
	return Tree.evaluateDouble(vars);
}

bool checkIfDouble(std::string expr)
{
	return std::regex_search(expr, std::regex("(\\.)|(cos)|(sin)|(tan)"));
}

void defineConstants()
{
  vars["pi"] = std::make_pair("Double", "3.141592653589793");
}

int main(int argc, char const *argv[])
{
	//Loop Principal
  defineConstants();
	bool zeroConverge = true;
	std::cout << "YetAnotherInterpreter - Versão 1.2" << std::endl << "Data: " <<__DATE__ << std::endl << "Hora: " << __TIME__ << std::endl;
  while(true)
  {
    try
    {
      std::string entry;
      char* input;
      input = readline("=>");
      add_history(input);
      if(input != nullptr)
        entry = std::string(input);
      else
        entry = "";
      if(match_assignment(entry))
      {
        std::vector<std::string> assignment = tokenize(entry, '=');
        assignment[0].erase(std::remove(assignment[0].begin(), assignment[0].end(), ' '), assignment[0].end());
        if(match_variable(assignment[0]))
        {
          if(checkIfDouble(assignment[1]))
          {
            vars[assignment[0]] = std::make_pair("Double", std::to_string(resolveDouble(assignment[1])));
          }
          else
          {
            vars[assignment[0]] = std::make_pair("Integer", std::to_string(resolveInteger(assignment[1])));
          }
          std::cout << vars[assignment[0]].second << std::endl;
        }
        else
        {
          throw std::runtime_error("Lado esquerdo não é uma variável.");
        }
      }
      else if(checkIfDouble(entry))
      {
        double output = resolveDouble(entry);
        if(zeroConverge && fabs(output) < 1e-10)
        {
          output = 0;
        }
        std::cout << output << std::endl;
      }
      else
      {
        long output = resolveInteger(entry);
        std::cout << output << std::endl;
      }
      free(input);
    }
    catch(const std::runtime_error& error)
    {
    std::cout << "Comando ignorado, " << error.what() << std::endl;
    }
  }
	return 0;
}
