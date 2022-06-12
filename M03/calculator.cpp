#include "calculator.h"

unsigned long long factorial(int n)
{
    if (n == 0 || n == 1) 
        return 1; 
    return n * factorial(n - 1);}

double factExp(double x, int n)
{
    double num = 1;
    for(int i = 1; i<= n ; i++)
    {
        num *= x/i;

    }
    return num;
}

double sin(double x, int nTerms)
{
    double sine = 0;
    for(int i = 1; i <= nTerms; i++)
    {
        if(i == 1)
        {
            sine += factExp(x,1);
        }
        else if(i % 2 ==0)
        {
            sine -= factExp(x,(2*i)-1);
        }
        else
        {
            sine += factExp(x,(2*i)-1);
        }
        


    }

    return sine;
}

double sqrt(double x, int nTerms)
{
    double prev = 1;
    double next;
    for(int j =0; j < nTerms ; j++)
    {
        next = prev - (((prev*prev)-x)/(2*prev));
        prev = next;
    }
    return next;
}

double primary()	// Number or �(� Expression �)�
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(':			       // handle �(�expression �)�
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");

        Token facto = ts.get();
        if(facto.kind == fact)
        {
            return factorial(d);
        }
        else
        {
            ts.putback(facto);
        }
        

        ///Look ahead for a fact Token here before returning d
        ///don't forget to put the Token back if it is not fact
        ///fix me
        return d;	// return the number�s value

    }

    case '-':
        return -primary();

    case number:	// rather than case '8':
    {
        ///Look ahead for a fact Token here before returning t's value
        ///don't forget to put the Token back if it is not fact
        ///fix me
        Token T = ts.get();
        if(T.kind == fact)
        {
            return factorial(t.value);
        }
        else
        {
            ts.putback(T);
        }
        
        return t.value;	// return the number�s value

    }
    /*case fact:
    {
        return factorial(primary());
    }*/


    ///if the token is of type sine, then
    ///call for a new primary
    ///pass that into the sin function
    ///use nTerms = 1000
    case sine:
        return sin(primary(),1000);

    ///if the token is of type root, then
    ///call for a new primary
    ///pass that into the sqrt function
    ///use nTerms = 1000
    case root:
        return sqrt(primary(),1000);

    default:
        error("primary expected");
        return 0;
    }
}

///The code below this line does not need to be changed at all

double expression()	// read and evaluate: 1   1+2.5   1+2+3.14  etc.
{
    double left = term(); 			// get the Term
    while (true)
    {
        Token t = ts.get();		// get the next token�
        switch (t.kind)  			// � and do the right thing with it
        {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.putback(t);

            return left;		// return the value of the expression
        }
    }
}
double term()	// exactly like expression(), but for * and  /
{
    double left = primary(); 		// get the Primary
    while (true)
    {
        Token t = ts.get();	// get the next Token
        switch (t.kind)
        {
        case '*':
            left *= primary();
            break;
        case '/':
        {
            double d = primary();
            if  (d==0)
                error("divide by zero");
            left /= d;
            break;
        }
        default:
            ts.putback(t);
            return left;	// return the value
        }
    }
}


void clean_up_mess()
{
    ts.ignore(print);
}


void calculate()
{
    while (cin)
        try
        {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t=ts.get();	// first discard all �prints�
            if (t.kind == quit)
                return;		// quit
            ts.putback(t);
            cout << result << expression() << endl;
        }
        catch (exception& e)
        {
            cerr << e.what() << endl;		// write error message
            clean_up_mess();		// <<< The tricky part!
        }
}
