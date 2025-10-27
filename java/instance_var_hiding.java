class Example{
  private int x = 10;
  public void setX(int x){
    System.out.println("Parameter x="+x);
    this.x=x;
  }
  public void display(){
    System.out.println("Instance variable x="+x);
  }
  
  public static void main(String[] args){
    Example obj = new Example();
    obj.setX(20);
    obj.display();
  }
}
