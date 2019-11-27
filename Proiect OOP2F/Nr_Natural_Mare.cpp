#include "Nr_Natural_Mare.h"

    Nr_Natural_Mare::Nr_Natural_Mare(int _nrcif,std::string numar):_nrcif(_nrcif),V(numar){}
    Nr_Natural_Mare::Nr_Natural_Mare():_nrcif(1),V(){}
    Nr_Natural_Mare::Nr_Natural_Mare(std::string numar):_nrcif([numar](){if(numar[0]=='-') return numar.length()-1; return numar.length();}()),V(numar){}
    Nr_Natural_Mare::Nr_Natural_Mare(const Nr_Natural_Mare& ob):_nrcif(ob._nrcif),V(ob.V){
        //cout<<"COPYCT1"<<endl;
        }
    void Nr_Natural_Mare::afisare()
    {
        V.afisare(this->_nrcif);
    }
    std::istream &operator>>(std::istream &ceva,Nr_Natural_Mare &nr)
    {
        try{
   std::string cev;
   ceva>>cev;
   nr._nrcif=cev.length();
   Vector *p=new Vector(cev);
    nr.V=(*p);
    delete p;
    return ceva;
        }
        catch(std::exception &e)
        {
            std::cout<<"Exception2"<<e.what();
        }
    }
    std::ostream &operator<<(std::ostream &ceva,Nr_Natural_Mare &nr)
    {

     for(int i=nr._nrcif-1;i>=0;i--)
        ceva<<nr.V[i];
    return ceva;
    }
    Nr_Natural_Mare& Nr_Natural_Mare::operator=(Nr_Natural_Mare nr)
    {
        try{
        _nrcif=nr._nrcif;
        V.alocate(_nrcif);
        for(int i=0;i<_nrcif;i++)
            V[i]=nr.V[i];
        return (*this);
        }
        catch(std::exception &e)
        {
            std::cout<<"Exception3"<<e.what();
        }

    }
    Nr_Natural_Mare Nr_Natural_Mare::operator+(Nr_Natural_Mare nr)
    {
         Nr_Natural_Mare c,c1,c2;
         c._nrcif=std::max(_nrcif,nr._nrcif);
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
    int Nr_Natural_Mare::absmaxim(Nr_Natural_Mare b,Nr_Natural_Mare c)
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
    Nr_Natural_Mare Nr_Natural_Mare::operator-(Nr_Natural_Mare nr)
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
            std::cout<<"Nu se realizeaza"<<std::endl;
            std::string rez="Unsuccesfull operation";
            throw rez;
        }
        }
        catch(std::string rez)
        {
            if(rez=="Unsuccesfull operation")
            std::cout<<"Terminating program";
                exit(EXIT_FAILURE);
        }
    }
    Nr_Natural_Mare Nr_Natural_Mare::operator*(Nr_Natural_Mare nr)
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
    Nr_Natural_Mare Nr_Natural_Mare::operator++()
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
    Nr_Natural_Mare Nr_Natural_Mare::operator++(int)
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
    Nr_Natural_Mare::~Nr_Natural_Mare(){}
