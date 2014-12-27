#include <phpcpp.h>
#include <cmath>
#include <iostream>
#include <sstream>

class Complex : public Php::Base {
    const double PI = 3.1415926;
    const double EPS = 1e-12;
    
private:
    double r = 0, i = 0;

public:

    Complex() {
    }

    virtual ~Complex() {
    }

    Php::Value getReal() {
        return r;
    }

    Php::Value getImage() {
        return i;
    }

    void __construct(Php::Parameters &params) {
        if (params.size() == 2) {
            r = params[0];
            i = params[1];
        } else {
            r = 0;
            i = 0;
        }
    }

    Php::Value mod() const {
        return (double) sqrt(r * r + i * i);
    }

    Php::Value phi() const {

        if (i * i < EPS) // Falls on X axis
        {
            if (r * r < EPS) // X is also 0
            {
                throw Php::Exception("Undefined");
            } else if (r > 0)
                return 0;
            else
                return PI;
        }

        if (r * r < EPS) //Falls on Y axis
        {
            if (i * i < EPS)
                throw Php::Exception("Undefined");
            else if (i > 0)
                return PI / 2;
            else
                return -PI / 2;
        }

        return atan2(i, r);
    }

    Php::Value __toString() {
        std::ostringstream os;
        os << r;
        if (i >= 0)
            os << '+';

        os << i << 'i';

        return os.str();
    }

    Php::Value add(Php::Parameters &params) {
        Php::Value t = params[0];
        Complex *a = (Complex *) t.implementation();

        r += (double) a->getReal();
        i += (double) a->getImage();

        return this;
    }

    Php::Value sub(Php::Parameters &params) {
        Php::Value t = params[0];
        Complex *a = (Complex *) t.implementation();

        r -= (double) a->getReal();
        i -= (double) a->getImage();

        return this;
    }

    Php::Value mul(Php::Parameters &params) {
        Php::Value t = params[0];
        Complex *a = (Complex *) t.implementation();

        double tr = r * (double) (a->getReal()) - i * (double) (a->getImage());
        double ti = i * (double) (a->getReal()) + r * (double) (a->getImage());

        r = tr;
        i = ti;
        return this;
    }

    Php::Value div(Php::Parameters &params) {
        Php::Value t = params[0];
        Complex *b = (Complex*) t.implementation();

        double t1 = b->mod() * b->mod();

        if (t1 < EPS)
            throw Php::Exception("Division by zero");

        double tr = r * (double) (b->getReal()) + i * (double) (b->getImage());
        double ti = i * (double) (b->getReal()) - r * (double) (b->getImage());

        r = tr / t1;
        i = ti / t1;

        return this;
    }

    Php::Value conjugate() {
        Complex *t = new Complex();

        t->r = r;
        t->i = -i;

        return Php::Object("tr\\Complex", t);
    }
};

/**
 *  tell the compiler that the get_module is a pure C function
 */
extern "C" {

    /**
     *  Function that is called by PHP right after the PHP process
     *  has started, and that returns an address of an internal PHP
     *  strucure with all the details and features of your extension
     *
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module() {
        // static(!) Php::Extension object that should stay in memory
        // for the entire duration of the process (that's why it's static)
        static Php::Extension extension("complex", "0.0.1");

        Php::Namespace myNamespace("tr");
        Php::Class<Complex> complex("Complex");

        complex.method("mod", &Complex::mod,{});
        complex.method("phi", &Complex::phi,{});

        complex.method("real", &Complex::getReal,{});
        complex.method("image", &Complex::getImage,{});

        complex.method("__construct", &Complex::__construct);

        complex.method("add", &Complex::add,{
            Php::ByVal("op", "tr\\Complex", false, true)
        });
        complex.method("sub", &Complex::sub,{
            Php::ByVal("op", "tr\\Complex", false, true)
        });
        complex.method("mul", &Complex::mul,{
            Php::ByVal("op", "tr\\Complex", false, true)
        });
        complex.method("div", &Complex::div,{
            Php::ByVal("op", "tr\\Complex", false, true)
        });

        complex.method("conjugate", &Complex::conjugate,{});

        complex.method("__toString", &Complex::__toString);

        myNamespace.add(std::move(complex));

        extension.add(std::move(myNamespace));
        //extension.add(std::move(complex));

        // return the extension
        return extension;
    }
}




