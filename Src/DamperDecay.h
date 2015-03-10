
/************************************************************************************************************
 * DamperDecay.h -
 ************************************************************************************************************/

#ifndef DamperDecay_h
#define DamperDecay_h


class DamperDecay {
  public:
    DamperDecay();

    void damper_set_new_target(float value); //simple aquisition
    void do_damper();//traitement de la donnée en damper
    void set_damper_decay(float value);
    void set_damper_mode(int mode);
    float return_dampered_data();

  private:
    bool _damper_do_calculation;
    int _damper_mode;//0 default , 1 montee plus rapide, descente plus lente
    float _damper_decay_constant;
    float _damper_vel;
    float _damper_dt;
    float _damper_val; //value
    float _damper_target_val;
    float _damper_previous_target;
    float _damper_accel;
    float _dampered_data;

};

#endif
