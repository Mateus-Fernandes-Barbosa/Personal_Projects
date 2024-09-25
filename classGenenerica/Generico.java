import java.lang.reflect.Constructor;

public class Generico <T extends Teste> {
    public T objeto;
    public Constructor <T> construtor;

    public Generico(Constructor<T> constructor){
        this.construtor = constructor;
        try{
            this.objeto = this.construtor.newInstance();
        }
        catch(Exception e){
            System.out.println("Deu bobs no construtor vazio da classe genérico");
            System.out.println(e.getMessage());
        }
    }

    public Generico(Constructor<T> constructor, int elemento){
        this.construtor = constructor;
        try{
            this.objeto = this.construtor.newInstance();
            this.objeto.setElemento(elemento);
        }
        catch(Exception e){
            System.out.println("Deu bobs no construtor com inteiro da classe genérico");
            System.out.println(e.getMessage());
        }
    }
}
