// Static initializer based Java implementation of singleton design pattern
// Use this method only when your singleton class is light and is used throughout the execution of your program
class Singleton {
    private static Singleton obj = new Singleton();

    private Singleton() {}

    public static Singleton getInstance() {
        return obj;
    }
}
