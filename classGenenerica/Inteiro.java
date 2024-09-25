public class Inteiro implements Teste{
    int elemento;

    public void setElemento(int elemento){
        this.elemento = elemento;
    }

    public Inteiro(int elemento){
        this.elemento = elemento;
    }

    public Inteiro(){
        this(0);
    }
}
