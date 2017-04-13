// ****************************************************************************
// File: snapper.cc
// Author: Nigel Struble (ASCII)
// Date: 7/05/2010
// Purpose: 	Class defenitions for the 3 snapper(gadget) objcets
//		(socket, snapper, light)
// ****************************************************************************

#ifndef __SNAPPER_H__
#define __SNAPPER_H__
class gadget{
	public:
		bool is_powered(void){return power;} //returns true if the gadget has power
		virtual void set_power(bool) {}
		virtual bool is_on() {return true;}
		virtual void toggle() {}
	protected:
		bool power;
};

class socket:public gadget{
	public:
		socket(){power = true;} // the socket always has power
};
class snapper:public gadget{
	public:
		snapper(){//the snapper starts without power, and in the off position
			power = false;
			state = false;
		} 
		bool is_on(void){return state;} //returns true if the snapper is in the on position
		void toggle(void){state = !state;} // toggles on/off
		void set_power(bool p){power = p;} //sets the power on the snapper
	private:
		bool state;
};
class light:public gadget{
	public:
		light(){power = false;} //the light starts without power
		void set_power(bool p){power = p;} //sets the power on the light
};
#endif
