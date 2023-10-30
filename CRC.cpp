#include <bits/stdc++.h>
using namespace std;

int main()
{

    // dividend
    int n;
    cout << "Enter the bits in data word" << endl;
    cin >> n;
    int data[n];
    cout << "Enter the data word" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    // divisor
    int m;
    cout << "Enter the bits in generating polynomial" << endl;
    cin >> m;
    int generate[m];
    cout << "Enter the generating polynomial" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> generate[i];
    }

    // appending (m-1) 0's at end of data word
    for (int i = n; i < n + m - 1; i++)
    {
        data[i] = 0;
    }

    // Dividend after appending 0's
    cout << "Dividend is : ";
    for (int i = 0; i < n + m - 1; i++)
    {
        cout << data[i];
    }

    // Division
    int check_value[m];
    int i;
    int j;
    for (i = 0; i < m; i++)
    {
        check_value[i] = data[i];
    }
    do
    {
        if (check_value[0] == 1)

            for (j = 1; j < m; j++)
            {
                check_value[j] = ((check_value[j] == generate[j]) ? 0 : 1);
            }

        for (j = 0; j < m - 1; j++)
        {
            check_value[j] = check_value[j + 1];
        }
        check_value[j] = data[i++];
    } while (i <= n + m - 1);

    // CRC
    cout << endl;
    cout << "CRC is : ";
    for (int i = 0; i < m - 1; i++)
    {
        cout << check_value[i];
    }

    // Codeword=dividend+remainder
    cout << endl;
    cout << "CodeWord is : ";

    for (int i = 0; i < m; i++)
    {
        data[n + i] = check_value[i];
    }

    for (int i = 0; i < n + m - 1; i++)
    {
        cout << data[i];
    }

    // Received Data
    cout << endl;
    int received[n + m - 1];
    cout << "Enter the received data" << endl;
    for (int i = 0; i < n + m - 1; i++)
    {
        cin >> received[i];
    }

    int check_error[m];
    for (i = 0; i < m; i++)
    {
        check_error[i] = received[i];
    }
    do
    {
        if (check_error[0] == 1)

            for (j = 1; j < m; j++)
            {
                check_error[j] = ((check_error[j] == generate[j]) ? 0 : 1);
            }

        for (j = 0; j < m - 1; j++)
        {
            check_error[j] = check_error[j + 1];
        }
        check_error[j] = received[i++];
    } while (i <= n + m - 1);

    // CRCs
    cout << endl;
    int flag = 0;
    cout << "CRC is of received data : ";
    for (int i = 0; i < m - 1; i++)
    {
        cout << check_error[i];
        if (check_error[i] == 1)
        {
            flag = 1;
            break;
        }
        else
            flag = 0;
    }

    cout << endl;
    if (flag)
        cout << "Error Detected" << endl;
    else
        cout << "NO Error Detected" << endl;

    return 0;
}