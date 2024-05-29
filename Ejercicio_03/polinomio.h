#pragma once
#include<vector>
using namespace std;

class Polinomio
{
public:
    Polinomio() :monomios() {};

    void AnadirMonomio(int coeficiente, int exponente)
    {
        int i = 0;

        while (i < monomios.size() && monomios[i].second <= exponente)
        {
            i++;
        }

        if (i < monomios.size())
        {
            if (monomios[i].second == exponente)
            {
                monomios[i].first += coeficiente;

                if (monomios[i].first == 0)
                {
                    for (int e = i; e < monomios.size() - 2; e++)
                    {
                        monomios[e] = monomios[e + 1];
                    }

                    monomios.resize(monomios.size() - 1);
                }
            }
            else
            {
                pair<int, int> aux;
                monomios.push_back(monomios[monomios.size() - 1]);

                for (int e = monomios.size() - 1; e > i; e--)
                {
                    monomios[e] = monomios[e - 1];
                }

                monomios[i] = pair<int, int>(coeficiente, exponente);
            }
        }
        else monomios.push_back(pair<int, int>(coeficiente, exponente));
    }

    long long int Evalua(int x)
    {
        long long int res = 0;
        long long int aux = 1;

        if (monomios.size() > 0)
        {
            for (int i = 0; i < monomios[0].second; i++) aux *= x;
            res += monomios[0].first * aux;
        }

        for (int i = 1; i < monomios.size(); i++)
        {
            for (int e = 0; e < monomios[i].second - monomios[i - 1].second; e++) aux *= x;
            res += monomios[i].first * aux;
        }

        return res;
    }

private:
    vector<pair<int, int>> monomios;
};
