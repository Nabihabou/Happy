# YetAnotherInterpreter
Um interpretador de expressões simples, escrito em C++.

<h2>Build:</h2>
<p>Para compilar, use g++ -std=c++14 -Wall main.cpp
BinaryExpressionTree.cpp utils.cpp -o Interpreter -lreadline
</p>

<h2>Opções em tempo de execução: </h2>
<p>
Por enquanto só existem duas flags:
</p>
<ul>
<li>disableIntegers</li>
<li style="text-decoration:none"> Todos os numeros são considerados do tipo flutuante.</li>
<li>disableZeroConvergence</li>
<li style="text-decoration:none"> Todos os numeros próximos de zero são exibidos em sua forma original, e não como zero.</li>
</ul>
