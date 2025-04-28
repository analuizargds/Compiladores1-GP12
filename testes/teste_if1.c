verificaPositivo(x)
{
    if (x > 0) {
        return 1;
    } else {
        return 0;
    }
}

classificaNumero(x)
{
    if (x > 0) {
        if (x > 10) {
            return 2;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

main() 
{
    resultado1 = verificaPositivo(10);
    resultado2 = classificaNumero(20);

    return 0;
}