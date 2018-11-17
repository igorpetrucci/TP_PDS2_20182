#ifndef SENSOR_H
#define SENSOR_H


class Sensor{
    public:
        Sensor();
        void Setnivel(double ni_);
        void Setvazao(double va_);
        void Settemperatura(double temp_);
        void Setpressao(double pres_);
        void Setconcentracao(double conce_);
        double Getnivel();
        double Getvazao();
        double Gettemperatura();
        double Getpressao();
        double Getconcentracao();
        ~Sensor();

    private:
        double nivel_;
        double vazao_;
        double temperatura_;
        double pressao_;
        double concentracao_;
};

#endif // SENSOR_H
