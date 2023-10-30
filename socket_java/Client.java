import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws IOException {
        Socket server = new Socket("localhost", 12345);
        BufferedReader in = new BufferedReader(new InputStreamReader(server.getInputStream()));
        PrintWriter out = new PrintWriter(server.getOutputStream(), true);
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.print("Enter first number (a): ");
            double a = sc.nextDouble();
            System.out.print("Enter second number (b): ");
            double b = sc.nextDouble();
            System.out.print("Enter operand (+, -, *, /, sin , cos): ");
            String operand = sc.next();

            String request = a + " " + operand + " " + b;
            out.println(request);

            if (request.equals("exit"))
                break;

            System.out.println("Server Response: " + in.readLine());
        }

        server.close();
    }
}
