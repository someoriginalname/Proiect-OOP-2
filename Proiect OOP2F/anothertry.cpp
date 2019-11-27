#include <iostream>
#include <string.h>
#include <exception>
using namespace std;
class Vector{
int *a;
public:
    Vector(string numar)
    {
        try{
        if(numar[0]=='-')
            numar=numar.erase(0,1);
        a=new int[numar.length()+1];
        for(int i=0;i<numar.length();i++)
          a[i]=static_cast<int>(numar[(numar.length()-1)-i]-48);
        }
        catch(exception &e)
        {
            cout<<"Exception 1"<<e.what();
        }

    }
    Vector()
    {
        a=new int[1];
        a[0]=0;
    }

    Vector(const Vector& ob)
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

    Vector& operator=(Vector ob)
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

    ~Vector()
    {
    delete[] a;
    }

    void afisare(int _nrcif)
    {
        for(int i=_nrcif-1;i>=0;i--)
            cout<<a[i];
    }
    void alocate(int _nrcif)
    {
     a=new int[_nrcif];
    }
    int& operator[](int nr)
    {
        return a[nr];
    }
    void getad()
    {
        cout<<a;
    }
    int* retad()
    {
        return a;
    }

};
class Nr_Natural_Mare{
protected:
    int _nrcif;
    Vector V;
public:
    Nr_Natural_Mare(int _nrcif,string numar):_nrcif(_nrcif),V(numar){}
    Nr_Natural_Mare():_nrcif(1),V(){}
    Nr_Natural_Mare(string numar):_nrcif([numar](){if(numar[0]=='-') return numar.length()-1; return numar.length();}()),V(numar){}
    Nr_Natural_Mare(const Nr_Natural_Mare& ob):_nrcif(ob._nrcif),V(ob.V){
        //cout<<"COPYCT1"<<endl;
        }
    void afisare()
    {
        V.afisare(this->_nrcif);
    }
    friend istream &operator>>(istream &ceva,Nr_Natural_Mare &nr)
    {
        try{
   string cev;
   ceva>>cev;
   nr._nrcif=cev.length();
   Vector *p=new Vector(cev);
    nr.V=(*p);
    delete p;
    return ceva;
        }
        catch(exception &e)
        {
            cout<<"Exception2"<<e.what();
        }
    }
    friend ostream &operator<<(ostream &ceva,Nr_Natural_Mare &nr)
    {

     for(int i=nr._nrcif-1;i>=0;i--)
        ceva<<nr.V[i];
    return ceva;
    }
    Nr_Natural_Mare& operator=(Nr_Natural_Mare nr)
    {
        try{
        _nrcif=nr._nrcif;
        V.alocate(_nrcif);
        for(int i=0;i<_nrcif;i++)
            V[i]=nr.V[i];
        return (*this);
        }
        catch(exception &e)
        {
            cout<<"Exception3"<<e.what();
        }

    }
    Nr_Natural_Mare operator+(Nr_Natural_Mare nr)
    {
         Nr_Natural_Mare c,c1,c2;
         c._nrcif=max(_nrcif,nr._nrcif);
         int r=0;
         if(absmaxim(*this,nr)==1)
         {
             c1=*this;
             c2=nr;
         }
         else
         {
             c1=nr;
             c2=*this;
         }
         for(int i=0;i<c._nrcif;i++)
         {
             if(i<c2._nrcif)
             {
             c.V[i]=c1.V[i]+c2.V[i]+r;
             r=c.V[i]/10;
             c.V[i]%=10;
             }
             else
             {
              c.V[i]=c1.V[i]+r;
             r=c.V[i]/10;
             c.V[i]%=10;
             }
         }
         if (r>0)
         {
             c._nrcif++;
             c.V[c._nrcif-1]=r;
         }
         return c;

    }
    int absmaxim(Nr_Natural_Mare b,Nr_Natural_Mare c)
    {
        if(b._nrcif>c._nrcif)
            return 1;
        else
            if(b._nrcif==c._nrcif)
        {
            for(int i=b._nrcif-1;i>=0;i--)
                if(b.V[i]<c.V[i])
                return 0;
            return 1;
        }
        return 0;
    }
    Nr_Natural_Mare operator-(Nr_Natural_Mare nr)
    {
        try{
         Nr_Natural_Mare c,c1,c2;
         c1=(*this);
         c2=nr;
         c._nrcif=0;
        if(absmaxim(c1,c2)==1)
        {
         int p1=0,p2=0;
         while(p1<c1._nrcif || p2<c2._nrcif)
         {
             if(p1<c1._nrcif && p2<c2._nrcif)
             {
                 if(c1.V[p1]<c2.V[p2])
                 {
                     c1.V[p1+1]-=1;
                     c1.V[p1]+=10;
                 }
                 c.V[p1]=c1.V[p1]-c2.V[p2];

             }
             else
             {
                 if(c1.V[p1]<0)
                 {
                    c1.V[p1]+=10;
                    c1.V[p1+1]-=1;
                 }
                  c.V[p1]=c1.V[p1];
             }
             c._nrcif++;
             p1++;
             p2++;

         }
         while(c.V[c._nrcif-1]==0 && c._nrcif>1)
            c._nrcif--;
         return c;

        }
        else
        {
            cout<<"Nu se realizeaza"<<endl;
            string rez="Unsuccesfull operation";
            throw rez;
        }
        }
        catch(string rez)
        {
            if(rez=="Unsuccesfull operation")
            cout<<"Terminating program";
                exit(EXIT_FAILURE);
        }
    }
    Nr_Natural_Mare operator*(Nr_Natural_Mare nr)
    {
         Nr_Natural_Mare c1,c2,c3;
          if(this->_nrcif>nr._nrcif)
          {
            c1=(*this);
            c2=nr;
          }
          else
          {
              c1=nr;
              c2=(*this);
          }
          int nre,r=0;
            c3._nrcif=0;
          for(int i=0;i<c1._nrcif;i++)
          {
              nre=i-1;
              for(int j=0;j<c2._nrcif;j++)
              {
                  if(i==0)
                  {
                      nre++;
                      c3._nrcif++;
                      c3.V[nre]=c1.V[i]*c2.V[j]+r;
                      r=c3.V[nre]/10;
                      c3.V[nre]%=10;

                  }
                  else
                  {
                      nre++;
                      if(nre==c3._nrcif)
                      {
                          c3._nrcif++;
                      c3.V[nre]=c1.V[i]*c2.V[j]+r;
                      r=c3.V[nre]/10;
                      c3.V[nre]%=10;
                      }
                      else
                      {
                       c3.V[nre]=c1.V[i]*c2.V[j]+r+c3.V[nre];
                      r=c3.V[nre]/10;
                      c3.V[nre]%=10;
                      }

                  }

              }
              if (r!=0)
              {
                  nre++;
                  c3._nrcif++;
                  c3.V[nre]=r;
                  r=0;
              }
          }

       if(c3.V[c3._nrcif-1]==0)
        c3._nrcif=1;
        return c3;

    }
    Nr_Natural_Mare operator++()
    {
         Nr_Natural_Mare c;
         int r=1;
         for(int i=0;i<_nrcif;i++)
         {
             V[i]+=r;
             r=V[i]/10;
             V[i]%=10;
         }
         if (r>0)
         {
             _nrcif++;
             V[_nrcif-1]=r;
         }
         c=(*this);
         return c;

    }
    Nr_Natural_Mare operator++(int)
    {
         Nr_Natural_Mare c;
         int r=1;
         for(int i=0;i<_nrcif;i++)
         {
             V[i]+=r;
             r=V[i]/10;
             V[i]%=10;
         }
         if (r>0)
         {
             _nrcif++;
             V[_nrcif-1]=r;
         }
         c=(*this);
         return c;

    }
    ~Nr_Natural_Mare(){}

};
class Nr_Intreg_Mare:public Nr_Natural_Mare{
char semn;
public:
    Nr_Intreg_Mare(char semn,int _nrcif,string numar):semn(semn),Nr_Natural_Mare(_nrcif,numar){}
    Nr_Intreg_Mare(int _nrcif,string numar):semn([&numar](){ if(numar[0]=='-') return numar[0]; return '+';}()),Nr_Natural_Mare(_nrcif,numar){}
    Nr_Intreg_Mare():semn('+'),Nr_Natural_Mare(){}
    Nr_Intreg_Mare(string numar):semn([&numar](){ if(numar[0]=='-') return numar[0]; return '+';}()),Nr_Natural_Mare(numar){}
    Nr_Intreg_Mare(const Nr_Intreg_Mare& ob):semn(ob.semn),Nr_Natural_Mare(ob){
    /**
    cout<<"COPYCTINTREG"<<endl;
    Vector* cop=const_cast<Vector*>(&ob.V);
    cop->afisare(_nrcif);
    cout<<"endl1"<<endl;
    */
    }
    void afisare()
    {
        if(semn=='-')
        cout<<semn;
        V.afisare(this->_nrcif);
    }
    friend istream &operator>>(istream &ceva,Nr_Intreg_Mare &nr)
    {
        try{
   string cev;
   ceva>>cev;
   if(cev[0]=='-')
   {
   nr.semn=cev[0];
   cev=cev.erase(0,1);
   }
   else
    nr.semn='+';
   nr._nrcif=cev.length();
   Vector *p=new Vector(cev);
    nr.V=(*p);
    delete p;
    return ceva;
        }
        catch(exception &e)
        {
            cout<<"Exception4"<<e.what();
        }
    }
    friend ostream &operator<<(ostream &ceva,Nr_Intreg_Mare &nr)
    {
     if(nr.semn=='-')
        ceva<<nr.semn;
     for(int i=nr._nrcif-1;i>=0;i--)
        ceva<<nr.V[i];
    return ceva;
    }
    void afisares()
    {
        cout<<semn<<endl<<_nrcif;
    }
    Nr_Intreg_Mare& operator=(Nr_Intreg_Mare nr)
    {
        try{
            //cout<<"EGAL"<<" "<<*this<<" "<<nr<<endl;
             _nrcif=nr._nrcif;
        V.alocate(_nrcif);
        for(int i=0;i<_nrcif;i++)
            V[i]=nr.V[i];
            semn=nr.semn;
        return *this;
        }
        catch(exception &e)
        {
            cout<<"Exception5"<<e.what();
        }

    }
    Nr_Intreg_Mare operator*(Nr_Intreg_Mare nr)
    {
        try{
         Nr_Intreg_Mare c1,c2,c3;
          if(this->_nrcif>nr._nrcif)
          {
            c1=(*this);
            c2=nr;
          }
          else
          {
              c1=nr;
              c2=(*this);
          }
          if(c1.semn==c2.semn)
            c3.semn='+';
          else
            c3.semn='-';
          int nre,r=0;
            c3._nrcif=0;
          for(int i=0;i<c1._nrcif;i++)
          {
              nre=i-1;
              for(int j=0;j<c2._nrcif;j++)
              {
                  if(i==0)
                  {
                      nre++;
                      c3._nrcif++;
                      c3.V[nre]=c1.V[i]*c2.V[j]+r;
                      r=c3.V[nre]/10;
                      c3.V[nre]%=10;

                  }
                  else
                  {
                      nre++;
                      if(nre==c3._nrcif)
                      {
                          c3._nrcif++;
                      c3.V[nre]=c1.V[i]*c2.V[j]+r;
                      r=c3.V[nre]/10;
                      c3.V[nre]%=10;
                      }
                      else
                      {
                       c3.V[nre]=c1.V[i]*c2.V[j]+r+c3.V[nre];
                      r=c3.V[nre]/10;
                      c3.V[nre]%=10;
                      }
                  }

              }
              if (r!=0)
              {
                  nre++;
                  c3._nrcif++;
                  c3.V[nre]=r;
                  r=0;
              }
          }

       if(c3.V[c3._nrcif-1]==0)
        c3._nrcif=1;
        return c3;
        }
        catch(exception &e)
        {
            cout<<"Exception*"<<e.what();
        }

    }
    Nr_Intreg_Mare operator+(Nr_Intreg_Mare nr)
    {
        try{
         Nr_Intreg_Mare c,c1,c2;
         c._nrcif=0;
        if(absmaxim((*this),nr)==1)
        {
         c1=(*this);
        c2=nr;
        }
        else
        {
        c2=(*this);
        c1=nr;
        }
        c.semn=c1.semn;
        if(c1.semn!=c2.semn)
        {
            int p1=0,p2=0;
         while(p1<c1._nrcif || p2<c2._nrcif)
         {
             if(p1<c1._nrcif && p2<c2._nrcif)
             {
                 if(c1.V[p1]<c2.V[p2])
                 {
                     c1.V[p1+1]-=1;
                     c1.V[p1]+=10;
                 }
                 c.V[p1]=c1.V[p1]-c2.V[p2];

             }
             else
             {
                 if(c1.V[p1]<0)
                 {
                    c1.V[p1]+=10;
                    c1.V[p1+1]-=1;
                 }
                  c.V[p1]=c1.V[p1];
             }
             c._nrcif++;
             p1++;
             p2++;

         }
         while(c.V[c._nrcif-1]==0 && c._nrcif>1)
            c._nrcif--;
        }
        else
        {
            c.semn=this->semn;
            c._nrcif=max(c1._nrcif,c2._nrcif);
            int r=0;
         for(int i=0;i<c._nrcif;i++)
         {
             if(i<c2._nrcif)
             {
             c.V[i]=c1.V[i]+c2.V[i]+r;
             r=c.V[i]/10;
             c.V[i]%=10;
             }
             else
             {
              c.V[i]=c1.V[i]+r;
             r=c.V[i]/10;
             c.V[i]%=10;
             }
         }
         if (r>0)
         {
             c._nrcif++;
             c.V[c._nrcif-1]=r;
         }

        }
        if(c.V[c._nrcif-1]==0)
            c.semn='+';

        return c;
        }
        catch(exception &e)
        {
            cout<<"Exception+"<<e.what();
        }

    }
    int absmaxim(Nr_Intreg_Mare b,Nr_Intreg_Mare c)
    {
        if(b._nrcif>c._nrcif)
            return 1;
        else
            if(b._nrcif==c._nrcif)
        {
            for(int i=b._nrcif-1;i>=0;i--)
                if(b.V[i]<c.V[i])
                return 0;
            return 1;
        }
        return 0;
    }
    Nr_Intreg_Mare operator-(Nr_Intreg_Mare nr)
    {
        try{
         Nr_Intreg_Mare c,c1,c2;
         c._nrcif=0;
        if(absmaxim(*this,nr)==1)
        {
            //cout<<*this<<" "<<nr<<endl;
         c1=(*this);
        c2=nr;
        c.semn=c1.semn;
        //cout<<c1<<" "<<c2<<endl;
        }
        else
        {
            //cout<<*this<<" "<<nr<<endl;
        c2=(*this);
        c1=nr;
        if(c1.semn=='+')
            c.semn='-';
        else
            c.semn='+';
            //cout<<c1<<" "<<c2<<endl;
        }
        if(c1.semn==c2.semn)
        {
            int p1=0,p2=0;
         while(p1<c1._nrcif || p2<c2._nrcif)
         {
             if(p1<c1._nrcif && p2<c2._nrcif)
             {
                 if(c1.V[p1]<c2.V[p2])
                 {
                     c1.V[p1+1]-=1;
                     c1.V[p1]+=10;
                 }
                 c.V[p1]=c1.V[p1]-c2.V[p2];

             }
             else
             {
                 if(c1.V[p1]<0)
                 {
                    c1.V[p1]+=10;
                    c1.V[p1+1]-=1;
                 }
                  c.V[p1]=c1.V[p1];
             }
             c._nrcif++;
             p1++;
             p2++;

         }
         while(c.V[c._nrcif-1]==0 && c._nrcif>1)
            c._nrcif--;
        }
        else
        {
            c.semn=this->semn;
            c._nrcif=max(c1._nrcif,c2._nrcif);
            int r=0;
         for(int i=0;i<c._nrcif;i++)
         {
             if(i<c2._nrcif)
             {
             c.V[i]=c1.V[i]+c2.V[i]+r;
             r=c.V[i]/10;
             c.V[i]%=10;
             }
             else
             {
              c.V[i]=c1.V[i]+r;
             r=c.V[i]/10;
             c.V[i]%=10;
             }
         }
         if (r>0)
         {
             c._nrcif++;
             c.V[c._nrcif-1]=r;
         }

        }
        if(c.V[c._nrcif-1]==0)
            c.semn='+';
        //cout<<"--------------------"<<endl<<c<<endl;
        return c;
        }
        catch(exception& e)
        {
            cout<<"Exception-"<<e.what();
        }



    }
    Nr_Intreg_Mare operator++()
    {
         Nr_Intreg_Mare c;
         Nr_Intreg_Mare r("1");
         c=(*this);
         c=(c+r);
         (*this)=(*this)+r;
         return c;

    }
    Nr_Intreg_Mare operator++(int)
    {
         Nr_Intreg_Mare c;
         Nr_Intreg_Mare r("1");
         c=(*this);
         c=(c+r);
         (*this)=(*this)+r;
         return c;

    }
    ~Nr_Intreg_Mare(){}
};
int main()
{
Nr_Natural_Mare *B;
Nr_Intreg_Mare N("-20000"),M("100"),D;
B=&N;
cout<<(D=N+N);


}
