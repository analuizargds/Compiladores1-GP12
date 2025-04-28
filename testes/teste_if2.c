categorizaValor(x)
{
    if (x == 1) {
        return 10;
    } else if (x == 2) {
        return 20;
    } else if (x == 5) {
        return 50;
    } else if (x == 10) {
        return 100;
    } else {
        return -1;
    }
}

main()
{
    resultado = categorizaValor(2);
    
    return 0;
}