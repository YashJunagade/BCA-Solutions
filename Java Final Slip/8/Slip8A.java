interface Shape {
  abstract double area();
}

final class Circle implements Shape {
  double radius;

  Circle(double r) {
    this.radius = r;
  }

  @Override
  public double area() {
    return Math.PI * radius * radius;
  }
}

final class Sphere implements Shape {
  double radius;

  Sphere(double r) {
    this.radius = r;
  }

  @Override
  public double area() {
    return 4 * Math.PI * radius * radius;
  }
}

public class Slip8A {
  public static void main(String[] args) {
    Circle c = new Circle(3);
    Sphere s = new Sphere(2);

    System.out.println("Area of Circle : " + c.area());
    System.out.println("Area of Sphere : " + s.area());
  }
}
