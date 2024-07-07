#!/bin/bash

# Gera três números aleatórios entre 1 e 100
num1=$((RANDOM % 100 + 1))
num2=$((RANDOM % 100 + 1))
num3=$((RANDOM % 100 + 1))


# Exibe os números gerados para verificação
echo "Números gerados: $num1 $num2 $num3"

# Executa o programa push_swap.exe com os números gerados
./push_swap.exe "$num1 $num2 $num3"
