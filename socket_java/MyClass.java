import java.io.*;
import java.net.Socket;
import java.net.ServerSocket;

public class MyClass {
    public static void main(String[] args) throws IOException {
        ServerSocket ss = new ServerSocket(12345);
        Socket server = ss.accept();
        BufferedReader in = new BufferedReader(new InputStreamReader(server.getInputStream()));
        PrintWriter out = new PrintWriter(server.getOutputStream(), true);

        while (true) {
            String clientRequest = in.readLine();
            System.out.println("Client request: " + clientRequest);

            String[] parts = clientRequest.split(" ");
            if (parts.length == 3) {
                double num1 = Double.parseDouble(parts[0]);
                String operator = parts[1];
                double num2 = Double.parseDouble(parts[2]);

                double result = 0.0;

                switch (operator) {
                    case "+":
                        result = num1 + num2;
                        break;
                    case "-":
                        result = num1 - num2;
                        break;
                    case "*":
                        result = num1 * num2;
                        break;
                    case "/":
                        if (num2 != 0) {
                            result = num1 / num2;
                        } else {
                            out.println("Error: Division by zero is not allowed.");
                            continue;
                        }
                        break;
                    case "sin":
                        result = Math.sin(Math.toRadians(num2)); // Calculate sine
                        break;
                    case "cos":
                        result = Math.cos(Math.toRadians(num2)); // Calculate cosine
                        break;
                    default:
                        out.println("Error: Invalid operator.");
                        continue;
                }

                out.println("Result: " + result);
            } else {
                out.println("Error: Invalid request format. Please send a request like '5 + 3' or 'sin 30'.");
            }
        }
    }
}

