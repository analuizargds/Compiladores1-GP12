quadrado(x)
{
    return x * x;
}

cubo(x)
{
    return x * quadrado(x);
}

operacaoCompleta(a, b)
{
    return cubo(a) + quadrado(b);
}

main()
{
    resultado = quadrado(5);
    resultado = cubo(3);
    resultado = operacaoCompleta(2, 4);
    resultado = operacaoCompleta(quadrado(2), cubo(1));
    return 0;
}