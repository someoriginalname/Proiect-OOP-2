#include "Vector.h"

Vector::Vector(std::string numar)
    {
        try{
        if(numar[0]=='-')
            numar=numar.erase(0,1);
        a=new int[numar.length()+1];
        for(int i=0;i<numar.length();i++)
          a[i]=static_cast<int>(numar[(numar.length()-1)-i]-48);
        }
        catch(std::exception &e)
        {
            std::cout<<"Exception 1"<<e.what();
        }

    }
    Vector::Vector()
    {
        a=new int[1];
        a[0]=0;
    }

    Vector::Vector(const Vector& ob)
    {

        /**
        cout<<"COPYCTVECTOR"<<endl;
        for(int i=0;i<5;i++)
           cout<<ob.a[i]<<" ";
           cout<<endl;
           */
             int*cop=ob.a;
            /**
            for(int i=0;i<5;i++)
           cout<<cop[i]<<" ";
           cout<<endl;
           */
           int i=0,nr=0;
           while(cop[i]<10)
           {
               nr++;
               i++;
            }
            a=new int[nr];
            i=0;
            while(cop[i]<10)
           {
               a[i]=cop[i];
               i++;
            }
            /**
        for(i=0;i<5;i++)
           cout<<a[i]<<" ";
           cout<<endl;
           */

    }

    Vector& Vector::operator=(Vector ob)
    {
            int*cop=ob.a;
           int i=0,nr=0;
           while(cop[i]<10)
           {
               nr++;
               i++;
            }
            a=new int[nr];
            i=0;
            while(cop[i]<10)
           {
               a[i]=cop[i];
               i++;
            }
           return (*this);

    }

    Vector::~Vector()
    {
    delete[] a;
    }

    void Vector::afisare(int _nrcif)
    {
        for(int i=_nrcif-1;i>=0;i--)
            std::cout<<a[i];
    }
    void Vector::alocate(int _nrcif)
    {
     a=new int[_nrcif];
    }
    int& Vector::operator[](int nr)
    {
        return a[nr];
    }
    void Vector::getad()
    {
        std::cout<<a;
    }
    int* Vector::retad()
    {
        return a;
    }
