#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



class polinom{
    private:
        int n; // Степень
        vector<int> k; // Вектор коэфициентов
        vector<int> s; // Вeктор степеней
        int x; // Просто x

        void stPolin(vector<int>& _s){
            int max = -1;
            for (int i = 0; i < _s.size(); i++){
                if (_s[i] > max){
                    max = _s[i];
                }
            }
            n = max;
        }

    public:
        polinom(vector<int>& _k, vector<int>& _s, int _x = 0){
            k = _k;
            s = _s;
            x = _x;
            stPolin(s);
        }

        polinom(const polinom &help){
            n = help.n;
            k = help.k;
            s = help.s;
            x = help.x;
        }

        ~polinom(){}

        void set_ksn(vector<int>& _k, vector<int>& _s){
            k = _k;
            s = _s;
            stPolin(s); // автоматическое определение степени
        }

        void set_x(int _x){
            x = _x;
        }

        int get_n(){
            return n;
        }

        vector<int>& get_k(){
            return k;
        }

        vector<int>& get_s(){
            return s;
        }

        int get_x(){
            return x;
        }

};

class vecpolinom{
    private:
        int n;
        vector<polinom> vp; 
    public:
        vecpolinom(int _n, vector<polinom>& _vp){
            n = _n;
            vp = _vp;
        }

        vecpolinom(const vecpolinom &help){
            n = help.n;
            vp = help.vp;
        }

        ~vecpolinom(){}

        void set(int _n, vector<polinom>& _vp){
            n = _n;
            vp = _vp;
        }

        int get_n(){
            return n;
        }

        vector<polinom>& get_vp(){
            return vp;
        }

};

int CountPol(vecpolinom x){ // Чисто технически работает
    return x.get_n();
}


polinom SumRazn(polinom v1, polinom v2, int fl = 0){ // Если флаг = 0 то суммируем, если 1 то вычитаем ВТОРОЙ полином из ПЕРВОГО
    vector<int> k;
    vector<int> s;
    vector<int> prk1;
    vector<int> prs1;
    vector<int> prk2;
    vector<int> prs2;

    prk1 = v1.get_k();
    prk2 = v2.get_k();
    prs1 = v1.get_s();
    prs2 = v2.get_s();

    int n1 = v1.get_n();
    int n2 = v2.get_n();
    int n = n2;
    int nres = 0;
    if (n1 > n2){ // Определяем наибольшую степень
        n = n1;
    }
    int h1 = prs1.size();
    int h2 = prs2.size();
    int h = h2;
    if (h1 > h2){ // определяем более длинный полином
        h = h1;
    }
    int m[n + 1];
    for (int i = 0; i < n + 1; i++){ // заполняем пустой массив, который отвечает за коэфициенты (индекс массива - степень)
        m[i] = 0;
    }
    
    for(int i = 0; i < h; i++){ // суммируем все коэфициенты у каждой из степеней (если в обоих полиномах одинаковые степени, суммируем их коэфициенты)
        if (h1 > i){
            m[prs1[i]] += prk1[i];
        }
        if (h2 > i){
            if (fl == 1){
                m[prs2[i]] -= prk2[i];
            }
            else{
                m[prs2[i]] += prk2[i];
            }
        } 
    }
    cout << endl;
    for (int i = 0; i < n + 1; i++){ // Формируем окончательный полином
        if (m[i] != 0){
            s.push_back(i);
            k.push_back(m[i]);
        }
    }
    polinom vres = {k, s};
    return vres;
}



int RESULT(polinom v){ // Подсчет результата
    int x = v.get_x();
    vector<int> k = v.get_k();
    int n = v.get_n();
    vector<int> s = v.get_s();
    int res = 0;
    for (int i = 0; i < s.size(); i++){
        res += pow(x, s[i]) * k[i];
        //cout << x << " " << k[i] << 
    }
    return res;
}




int main(){
    cout << "SEICHAS BUDET EXPEREMENT!" << endl << "Y VAS EST 2 VECTORA POLINOMOV" << endl;
    cout << "VVEDITE KOLICHESTVO POLINOMOV V OBOIH VECTORAH:" << endl;
    int n;
    cin >> n;
    int el;
    vector<polinom> vecv1;
    vector<polinom> vecv2;
    cout << "VVEDITE PERVYI VECPOLINOM (1. koef 2. stepeni):" << endl;
    for (int i = 0; i < n; i++){
        cout << "------------------------------" << endl;
        vector<int> k;
        vector<int> s;
        cout << "VVEDITE NENULEVUH KOLICHESTVO STEPENEI V POLINOME:" << endl;
        int st;
        cin >> st;
        cout << "VVEDITE KOEFICIENTY V POLINOME:" << endl;
        for (int j = 0; j < st; j++){
            cin >> el;
            k.push_back(el);
        } 
        cout << "VVEDITE STEPENI V POLINOME:" << endl;
        for (int j = 0; j < st; j++){
            cin >> el;
            s.push_back(el);
        } 
        polinom v(k, s);
        vecv1.push_back(v);
    }

    cout << "VVEDITE VTOROI VECPOLINOM (1. koef 2. stepeni):" << endl;
    for (int i = 0; i < n; i++){
        cout << "------------------------------" << endl;
        vector<int> k;
        vector<int> s;
        cout << "VVEDITE KOLICHESTVO NENULEVUH STEPENEI V POLINOME:" << endl;
        int st;
        cin >> st;
        cout << "VVEDITE KOEFICIENTY V POLINOME:" << endl;
        for (int j = 0; j < st; j++){
            cin >> el;
            k.push_back(el);
        } 
        cout << "VVEDITE STEPENI V POLINOME:" << endl;
        for (int j = 0; j < st; j++){
            cin >> el;
            s.push_back(el);
        } 
        polinom v(k, s);
        vecv2.push_back(v);
    }
    
    vecpolinom v1(n, vecv1);
    vecpolinom v2(n, vecv2);
    
    vector<polinom> result;
    for (int i = 0; i < n; i++){
        result.push_back(SumRazn(v1.get_vp()[i], v2.get_vp()[i]));
    }
    vecpolinom vout(n, result);
    vout.get_vp()[0].set_x(2);
    cout << RESULT(vout.get_vp()[0]) << endl;
    // vector<int> k1 = {1, 1, 1};
    // vector<int> s1 = {1, 3, 5};
    // polinom v1(k1, s1);

    // vector<int> k2 = {2, 1};
    // vector<int> s2 = {1, 3};
    // polinom v2(k2, s2);

    // vector<polinom> x = {v1, v2};
    // vecpolinom h1(2, x);

    // polinom help = SumRazn(h1.get_vp()[1], h1.get_vp()[0]);
    // help.set_x(2);
    // cout << RESULT(help);
    // polinom vout = SumRazn(v1, v2); // Разность т.к. флаг равен 1 см. выше
    // cout << vout.get_s().size() << endl;
    // vout.set_x(2);
    // cout << RESULT(vout) << endl;


}