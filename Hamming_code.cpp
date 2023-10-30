#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Input
    int n;
    cout << "Enter no of data bits" << endl;
    cin >> n;

    int data_bits[n];
    cout << "Enter the bits" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data_bits[i];
    }

    cout << "The data bits are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << data_bits[i];
    }
    cout << endl;

    // Calculating the no of parity bits
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        if (pow(2, i) >= n + i + 1)
        {
            break;
        }
        else
        {
            p++;
        }
    }

    cout << "No of parity bits are: " << p << endl;

    // Hamming code generation

    int hamming_code[n + p];

    // Put data bits in hamming code
    for (int i = n + p - 1, j = n - 1; i >= 0; i--)
    {
        if (ceil(log2(n + p - i)) == floor(log2(n + p - i)))
        {
            hamming_code[i] = 2;
        }
        else
        {
            hamming_code[i] = data_bits[j];
            j--;
        }
    }

    // Place parity bits in hamming code
    //  int jmp;
    //  for(int i=n+p-1;i>=0;i--){
    //      if(hamming_code[i]==2){
    //          jmp=pow(2,log2(n+p-i));
    //     }
    // }

    hamming_code[n + p - 1] = hamming_code[n + p - 3] ^ hamming_code[n + p - 5] ^ hamming_code[n + p - 7];
    hamming_code[n + p - 2] = hamming_code[n + p - 3] ^ hamming_code[n + p - 6] ^ hamming_code[n + p - 7];
    hamming_code[n + p - 4] = hamming_code[n + p - 5] ^ hamming_code[n + p - 6] ^ hamming_code[n + p - 7];

    cout << "The hamming code generated is:" << endl;
    for (int i = 0; i < n + p; i++)
    {
        cout << hamming_code[i];
    }
    cout << endl;

    int received[n + p];
    cout << "Enter the received code :" << endl;
    for (int i = 0; i < n + p; i++)
    {
        cin >> received[i];
    }

    cout << "Received code is :" << endl;
    for (int i = 0; i < n + p; i++)
    {
        cout << received[i];
    }
    cout << endl;

    int temp[3];
    temp[0] = received[n + p - 1] ^ received[n + p - 3] ^ received[n + p - 5] ^ received[n + p - 7];
    temp[1] = received[n + p - 2] ^ received[n + p - 3] ^ received[n + p - 6] ^ received[n + p - 7];
    temp[2] = received[n + p - 4] ^ received[n + p - 5] ^ received[n + p - 6] ^ received[n + p - 7];

    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += temp[i] * pow(10, i);
    }

    int error_bit;
    for (int i = 0; sum != 0; ++i)
    {
        int rem = sum % 10;
        sum = sum / 10;
        error_bit = error_bit + (rem) * (pow(2, i));
    }

    cout << "Error in the bit: " << error_bit << endl;

    // Jugaad tarika
    //  for (int i = 0; i < n + p; i++)
    //  {
    //      if (hamming_code[i] != received[i])
    //      {
    //          cout << "Error in the bit number: " << i + 1 << endl;
    //          break;
    //      }
    //  }

    return 0;
}
