escolheOpcao(opcao)
{
    switch (opcao) {
        case 1:
            return 100;
            break;
        case 2:
            return 200;
            break;
        case 3:
            return 300;
            break;
        default:
            return 0;
            break;
    }
}

main()
{
    resultado = escolheOpcao(3); 
    
    return 0;
}