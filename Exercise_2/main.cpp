#include <fstream>
#include <iomanip>

using namespace std;

int main (){
    ifstream data("data.csv");
    ofstream result("result.txt");
    string s;

    data >> s;
    double S = stod(s.substr(2,  string::npos));
    data >> s;
    int n = stoi(s.substr(2,  string::npos));

    result << fixed << setprecision(2) << "S = " << S << ", n = " << n << endl;
    result << defaultfloat;

    double* w = new double[n];
    double* r = new double[n];


    data >> s;  // brucio la riga w;r

    // LETTURA DI W e R
    for(size_t i = 0; i < n; i++){
        data >> s;
        size_t pos = s.find(";", 0);
        w[i] = stod(s.substr(0,pos));
        r[i] = stod(s.substr(pos+1, string::npos));
    }


    // STAMPA DI -> w = [ ... ]
    result << "w = [ ";
    for(size_t i = 0; i < n; i++){
        result << w[i] << " ";
    }
    result << "]" << endl;

    // STAMPA DI -> r = [ ... ]
    result << "r = [ ";
    for(size_t i = 0; i < n; i++){
        result << r[i] << " ";
    }
    result << "]" << endl;


    // CALCOLO DI RATE e V
    double rate=0, V=0;
    for(size_t i = 0; i < n; i++){
        rate = rate + w[i]*r[i];
    }
    V = (1+rate)*S;

    // STAMPA DI RATE e V
    result << defaultfloat << setprecision(6) << "Rate of return of the portfolio: " << rate << endl;
    result << fixed << setprecision(2) << "V: " << V << endl;


    delete[] w;
    delete[] r;
    result.close();
    data.close();
    return 0;
}
