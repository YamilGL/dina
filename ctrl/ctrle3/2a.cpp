#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función para convertir un número binario a decimal
int binaryToDecimal(const string& binary) {
    int decimal = 0;
    int n = binary.size();

    for (int i = 0; i < n; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, n - 1 - i);
        }
    }

    return decimal;
}

// Función para convertir un número decimal a binario
string decimalToBinary(int decimal) {
    if (decimal == 0) {
        return "0";
    }

    string binary = "";
    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }

    return binary;
}

// Algoritmo de "divide y vencerás" para la multiplicación de enteros binarios
string multiplyBinary(const string& A, const string& B) {
    int n = max(A.size(), B.size());

    // Completa los números binarios con ceros a la izquierda para que tengan la misma longitud
    string binA = string(n - A.size(), '0') + A;
    string binB = string(n - B.size(), '0') + B;

    if (n == 1) {
        // Caso base: multiplicación de bits individuales
        int result = (binA[0] - '0') * (binB[0] - '0');
        return to_string(result);
    }

    int mid = n / 2;

    // Divide los números en mitades
    string Aleft = binA.substr(0, mid);
    string Aright = binA.substr(mid);
    string Bleft = binB.substr(0, mid);
    string Bright = binB.substr(mid);

    // Conquista: Multiplicación de las mitades
    string P1 = multiplyBinary(Aleft, Bleft);
    string P2 = multiplyBinary(Aright, Bright);
    string P3 = multiplyBinary(decimalToBinary(binaryToDecimal(Aleft) + binaryToDecimal(Aright)),
                                decimalToBinary(binaryToDecimal(Bleft) + binaryToDecimal(Bright)));

    // Combina los resultados
    int shift = n % 2 == 0 ? mid : mid + 1;
    string result = decimalToBinary(binaryToDecimal(P1) * pow(2, 2 * shift) +
                                    (binaryToDecimal(P3) - binaryToDecimal(P1) - binaryToDecimal(P2)) * pow(2, shift) +
                                    binaryToDecimal(P2));

    return result;
}

int main() {
    string A = "10011011";
    string B = "10111010";

    cout << "Multiplicando los números binarios A = " << A << " y B = " << B << endl;

    string result = multiplyBinary(A, B);

    cout << "El resultado de la multiplicación es: " << result << endl;

    return 0;
}



//imo
#include<iostream>
#include<string>
using namespace std;

// Función para realizar la suma de dos números binarios representados como cadenas
string binaryAddition(string a, string b) {
    int carry = 0;
    string result = "";

    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int bitA = i >= 0 ? a[i--] - '0' : 0;
        int bitB = j >= 0 ? b[j--] - '0' : 0;
        int sum = bitA + bitB + carry;
        result = to_string(sum % 2) + result;
        carry = sum / 2;
    }

    return result;
}

// Función para multiplicar dos números binarios representados como cadenas
string binaryMultiply(string A, string B) {
    int n = A.length();

    // Caso base: Si los números son de un solo dígito, multiplicarlos directamente
    if (n == 1) {
        int a = A[0] - '0';
        int b = B[0] - '0';
        int result = a * b;
        return to_string(result);
    }

    // Dividir los números en partes A1, A0, B1 y B0
    int halfN = n / 2;
    string A1 = A.substr(0, halfN);
    string A0 = A.substr(halfN);
    string B1 = B.substr(0, halfN);
    string B0 = B.substr(halfN);

    // Multiplicación recursiva
    string C1 = binaryMultiply(A1, B1);
    string C0 = binaryMultiply(A0, B0);

    // Combinar los resultados
    string result = C1 + string(n, '0') + C0;

    // Realizar sumas para obtener el resultado final
    return binaryAddition(result, C1 + string(halfN, '0') + C0);
}

string pushFront(string original, char character) {
    return character + original;
}
string BinaryMultiply(string A,string B)
{
    int size = A.length();

    string result;
    for(int j = 0;j<size-1;j++)
    {
        result.push_back('0');
    }
    bool acarreoB =0;
    for(int i =1; i <= size;i++)
    {
        if(B[size-i] == '0')
        {
            result = pushFront(result,'0');
        }
        else if(B[size-i] =='1')
        {

            if(acarreoB ==0)
            {
                result = pushFront(result,'0');
                acarreoB = 0;
            }
            int acarreo = 0;
            for(int j = size-1;j>=0;j--)
            {

                int value1 = result[j] - '0';
                int value2 = A[j] - '0';
                int sum = value1+value2+acarreo;
                if(sum == 3)
                {
                    acarreo = 1;
                    sum = 1;
                }
                else if(sum == 2)
                {
                    acarreo = 1;
                    sum = 0;
                }
                else{
                    acarreo = 0;
                }
                string suma =std::to_string(sum);
                result[j] = suma[0];
                if(acarreo!= 0 && j ==0)
                {
                    result = pushFront(result,'1');
                    acarreoB = 1;
                }
            }
        }
    }


    return result;

}
int main() {
    string A = "10011011";
    string B = "10111010";

    // Asegurarse de que ambas cadenas tengan la misma longitud
    int maxLen = max(A.length(), B.length());
    A = string(maxLen - A.length(), '0') + A;
    B = string(maxLen - B.length(), '0') + B;

    cout<<"Binary A:"<<A<<"\nBinary B: "<<B<<endl;
    string result = BinaryMultiply(A,B);

    //string result = binaryMultiply(A, B);
    cout << "Resultado en binario: " << result << endl;

    return 0;
}