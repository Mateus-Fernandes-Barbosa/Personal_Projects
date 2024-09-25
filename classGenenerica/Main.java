public class Main {    
    public static void main(String[] args) {
        Generico<Inteiro> teste;
        try {
            teste = new Generico<>(Inteiro.class.getConstructor());
            System.out.println("Objeto: " + teste.objeto + " - Elemento: " + teste.objeto.elemento);
            teste = new Generico<>(Inteiro.class.getConstructor(), 9);
            System.out.println("Objeto: " + teste.objeto + " - Elemento: " + teste.objeto.elemento);
            } catch (Exception e) {
                System.out.println("Deu bobs");
                e.printStackTrace();
            }
    }
}
