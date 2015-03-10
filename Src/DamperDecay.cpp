#include <DamperDecay.h>

DamperDecay::DamperDecay()
{
    _damper_mode=0;
    _damper_decay_constant = 0.6;

    _damper_vel= 0.1;
    _damper_dt= 0.1;
    _damper_val= 0.0;
    _damper_target_val= 0.0;
    _damper_previous_target=0.0;
    _damper_accel=0.0;
    _damper_do_calculation=0;
    _dampered_data=0;

}

////////////////////////////////////////////////////
void DamperDecay::set_damper_decay(float value)
{
 _damper_decay_constant=value;
 if (_damper_decay_constant<.1) _damper_decay_constant=.1;
}


void DamperDecay::set_damper_mode(int mode)
{
    _damper_mode=mode;
}


void DamperDecay::damper_set_new_target(float value)//
{
_damper_target_val=value;
}

float DamperDecay::return_dampered_data()
{
    return(_dampered_data);
}

void DamperDecay::do_damper()
{

//if(_damper_do_calculation==1)
//{
_damper_previous_target=_damper_target_val;
    switch (_damper_mode)
    {
    case 1://elastic effect
    _damper_accel = (_damper_target_val - _damper_val) * 1 - _damper_vel *  _damper_decay_constant;
    _damper_vel += _damper_accel * _damper_dt;
    _damper_val += _damper_vel * _damper_dt;
    break;
    case 2:
    _damper_vel = (_damper_target_val - _damper_val) * _damper_decay_constant;
    _damper_val += _damper_vel * _damper_dt;
    break;
    default://in out egaux
    _damper_vel= (_damper_target_val-_damper_val)* _damper_decay_constant;
    _damper_val+=(_damper_vel*_damper_dt)* _damper_decay_constant;
    break;
    }
    if(_damper_val<0.0){_damper_val=0.0; _damper_do_calculation=0;}
    else if(_damper_val>1.0){_damper_val=1.0; _damper_do_calculation=0;}
//}

_dampered_data=_damper_val;
}

////////////////////////////////////////////////////


