#include "Nr_Intreg_Mare.h"
    Nr_Intreg_Mare::Nr_Intreg_Mare(char semn,int _nrcif,std::string numar):semn(semn),Nr_Natural_Mare(_nrcif,numar){}
    Nr_Intreg_Mare::Nr_Intreg_Mare(int _nrcif,std::string numar):semn([&numar](){ if(numar[0]=='-') return numar[0]; return '+';}()),Nr_Natural_Mare(_nrcif,numar){}
    Nr_Intreg_Mare::Nr_Intreg_Mare():semn('+'),Nr_Natural_Mare(){}
    Nr_Intreg_Mare::Nr_Intreg_Mare(std::string numar):semn([&numar](){ if(numar[0]=='-') return numar[0]; return '+';}()),Nr_Natural_Mare(numar){}
    Nr_Intreg_Mare::Nr_Intreg_Mare(const Nr_Intreg_Mare& ob):semn(ob.semn),Nr_Natural_Mare(ob){
    /**
    cout<<"COPYCTINTREG"<<endl;
    Vector* cop=const_cast<Vector*>(&ob.V);
    cop->afisare(_nrcif);
    cout<<"endl1"<<endl;
    */
    }
    void Nr_Intreg_Mare::afisare()
    {
        if(semn=='-')
        std::cout<<semn;
        V.afisare(this->_nrcif);
    }
    std::istream &operator>>(std::istream &ceva,Nr_Intreg_Mare &nr)
    {
        try{
   std::string cev;
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
        catch(std::exception &e)
        {
            std::cout<<"Exception4"<<e.what();
        }
    }
     std::ostream &operator<<(std::ostream &ceva,Nr_Intreg_Mare &nr)
    {
     if(nr.semn=='-')
        ceva<<nr.semn;
     for(int i=nr._nrcif-1;i>=0;i--)
        ceva<<nr.V[i];
    return ceva;
    }
    void Nr_Intreg_Mare::afisares()
    {
        std::cout<<semn<<std::endl<<_nrcif;
    }
    Nr_Intreg_Mare& Nr_Intreg_Mare::operator=(Nr_Intreg_Mare nr)
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
        catch(std::exception &e)
        {
            std::cout<<"Exception5"<<e.what();
        }

    }
    Nr_Intreg_Mare Nr_Intreg_Mare::operator*(Nr_Intreg_Mare nr)
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
        catch(std::exception &e)
        {
            std::cout<<"Exception*"<<e.what();
        }

    }
    Nr_Intreg_Mare Nr_Intreg_Mare::operator+(Nr_Intreg_Mare nr)
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
            c._nrcif=std::max(c1._nrcif,c2._nrcif);
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
        catch(std::exception &e)
        {
            std::cout<<"Exception+"<<e.what();
        }

    }
    int Nr_Intreg_Mare::absmaxim(Nr_Intreg_Mare b,Nr_Intreg_Mare c)
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
    Nr_Intreg_Mare Nr_Intreg_Mare::operator-(Nr_Intreg_Mare nr)
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
            c._nrcif=std::max(c1._nrcif,c2._nrcif);
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
        catch(std::exception& e)
        {
            std::cout<<"Exception-"<<e.what();
        }



    }
    Nr_Intreg_Mare Nr_Intreg_Mare::operator++()
    {
         Nr_Intreg_Mare c;
         Nr_Intreg_Mare r("1");
         c=(*this);
         c=(c+r);
         (*this)=(*this)+r;
         return c;

    }
    Nr_Intreg_Mare Nr_Intreg_Mare::operator++(int)
    {
         Nr_Intreg_Mare c;
         Nr_Intreg_Mare r("1");
         c=(*this);
         c=(c+r);
         (*this)=(*this)+r;
         return c;

    }
    Nr_Intreg_Mare::~Nr_Intreg_Mare(){}
