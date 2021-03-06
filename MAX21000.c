/******************************************************************************
*
* File: MAX21000.c
*
* Source code for MAX21000 configuration
*
* Purpose of this library is to give an example of the use of the device
*
* *Version:* 1.1beta
*
* *Property of* Maxim Integrated <http://www.maximintegrated.com>
*
* *Author*: Ivo Binda <ivo.binda@maximintegrated.com>
*
*******************************************************************************
*
* _Last change_: Sep/28/2012
*
******************************************************************************/

//#include "sensors/MAX21000.h"
//#include "sensors/MAX21000_map.h"
//#include "platform/platformInterface.h"

#include "MAX21000.h"
#include "MAX21000_map.h"
//#include "platform/platformInterface.h"

/************************************************************
*								
* Constant: USE_LOCAL						
*								
* This constant is used to define if a local image of the registers values 	
* is defined and used						
*								
* 								
************************************************************/
// #define USE_LOCAL

#ifdef USE_LOCAL

/******************************************************************************
* Struct: localSetting
*
* This is the structure containing the setting information of the MAX21000
* The structure is defined only if USE_LOCAL constant is defined.
*
* Element of the structure are:
*
*	powerMode	 - 	Power Mode setting
*	channel		 - 	Axes enable setting
*	bandwidth	 - 	Low pass Bandwidth setting
*	fullScale	 - 	Full scale setting
*	odr		 - 	Output data rate setting
*	oisFullscale	 - 	OIS full scale setting
*	dataSource	 - 	Digital data chain configuration
*	hpCutOff	 - 	high pass cut off frequency configuration
*	endianMode	 - 	Big Little endian configuration
*	dataReadyRstMode - 	Data ready reset mode configuration
*	auxPUD		 - 	dataSync pin pull-up and pull-down configuration
*	int1PUD		 - 	INT1 pin pull-up and pull-down configuration
*	int2PUD		 - 	INT2 pin pull-up and pull-down configuration
*	i2cMode		 - 	I2C interface configuration (standard/fast/HS)
*	padCur		 - 	pin current configuration
*	i2cOff		 - 	I2C interface turn on and off
*	dataStatus	 - 	Data Status of the sensor
*
* See Also:
*	<USE_LOCAL>
******************************************************************************/
struct localSetting
{
	unsigned char powerMode;
	unsigned char channel;
	unsigned char bandwidth;
	unsigned char fullScale;
	unsigned char odr;
	unsigned char maxOdr;
	unsigned char oisFullscale;
	unsigned char dataSource;
	unsigned char hpCutOff;
	unsigned char endianMode;
	unsigned char dataReadyRstMode;
	unsigned char auxPUD;
	unsigned char int1PUD;
	unsigned char int2PUD;
	unsigned char i2cMode;
	unsigned char padCur;
	unsigned char i2cOff;
	unsigned char dataStatus;
};

struct localSetting MAX21000;

#endif

/******************************************************************************
* Function: getPar
*
* Read the register containing the specified parameter and return only the
* value of the specified parameter
*
* Parameters:
*
*	device		 - 	it the I2C slave address or the code for the
*				SPI CS identification
*	paramBank	 - 	register bank containing the register
*	paramReg	 - 	register address containing the param
*	paramMask	 - 	mask of the register for the param bits
*	paramPos	 - 	parameter position
*	paramVal	 - 	pointer to the parameter value
*
* Return:
*	-1 if a communication error occurs
*	 1 if the parameter is updated
******************************************************************************/
signed char getPar (unsigned char device, unsigned char paramBank,
		    unsigned char paramReg, unsigned char paramMask,
		    unsigned char paramPos, unsigned char *paramVal)
{
	signed char err = -1;
	if (paramBank != BANK_CB) {
		if (writeCmd(device, REG_CB_33, paramBank))
			err = 1;
	} else
		err = 1;
	if (err == 1) {
		if (readCmd(device, paramReg, paramVal))
			err = 1;
		else
			err = -1;
	}
	return (err);
}

/******************************************************************************
* Function: setPar
*
* Write the specified parameter in the register containing the that parameter
*
* Parameters:
*
*	device		 -	it is the I2C slave address or the code for the
*				SPI's CS identification
*	paramBank	 -	register bank containing the register
*	paramReg	 -	register address containing the param
*	paramMask	 -	mask of the register for the param bits
*	paramPos	 -	parameter position
*	paramVal	 -	parameter value
*
* Returns:
*	-1 if a communication error occurs
*	 1 if the parameter is updated
******************************************************************************/
signed char setPar (unsigned char device, unsigned char paramBank,
		    unsigned char paramReg, unsigned char paramMask,
		    unsigned char paramPos, unsigned char paramVal)
{
	signed char err = -1;
	unsigned char tmpVar;

	if (paramBank != BANK_CB) {
		if (writeCmd(device, BANK_SEL_REG, paramBank))
			err = 1;
	} else
		err = 1;

	if (err == 1) {
		if (readCmd(device, paramReg, &tmpVar)) {
			// Use the below if the parameter are relative
			// tmpVar = (tmpVar & ~paramMask) | (paramVal<<paramPos);
			tmpVar = (tmpVar & ~paramMask) | paramVal;
			if (writeCmd(device, paramReg, tmpVar))
				err = 1;
			else
				err = -1;
		}
		else
			err = -1;
	}
	return (err);
}

/******************************************************************************
* Function: init_max21000
*
* Standard initialization for MAX21000
* This is the basis function for the MAX21000 configuration
*
* *Type*: Complex Function
*
* Parameters:
*	powerMode	 - 	select the power mode of the gyro.
*	channel		 - 	set the active channel.
*	bandwidth	 - 	set the data bandwidth.
*	fullScale	 - 	set the full scale.
*	odr		 - 	set the output data rate.
*
* Return:
*	-1 if an error occurs.
******************************************************************************/
signed char init_max21000 (unsigned char powerMode, unsigned char channel,
			   unsigned char bandwidth, unsigned char fullScale,
			   unsigned char odr)
{
	signed char err = -1;
	unsigned char regVal;
	if ((readCmd(SLAVE_ADD_AMU,WHO_AM_I_REG, &regVal) > 0) &&
	    (regVal  == WHO_AM_I)) {
		// select bank 0
		if (writeCmd(SLAVE_ADD_AMU, BANK_SEL_REG, BANK_00))
		//	0x07);	//0x0F); //
			if (writeCmd(SLAVE_ADD_AMU, SENSE_CFG0, fullScale|powerMode|channel))
				if (writeCmd(SLAVE_ADD_AMU, SENSE_CFG1, bandwidth))
					if (writeCmd(SLAVE_ADD_AMU, SENSE_CFG2, odr)) {
#ifdef USE_LOCAL
						extern struct localSetting MAX21000;
						MAX21000.bandwidth = bandwidth;
						MAX21000.powerMode = powerMode;
						MAX21000.channel = channel;
						MAX21000.fullScale = fullScale;
						MAX21000.odr = odr;
						MAX21000.oisFullscale = OIS_FS_OFF;
						MAX21000.maxOdr = SET_MAX_ODR_10K;
#endif
						err = 1;
					}
	}
	return (err);
}

/******************************************************************************
* Function: getRatef_max21000
*
* Read 3channels 16bits and return floating
*
* This is the basis function for the MAX21000 output reading
*
* *Type*: Complex Function
*
* Parameter:
*	rates - pointer to the rates values.
*
* Return:
*	-1 if an error occur.
******************************************************************************/
signed char getRatef_max21000 (float * rates)
{
	signed char err;
	char rateVect[6];

//	err = multiReadI2C(SLAVE_ADD_AMU,0x23, 0x06, (unsigned char *)rateVect);
	err = readMultiCmd(SLAVE_ADD_AMU,0x23, 0x06, (unsigned char *)rateVect);
	if(err > 0)
	{
		rates[0] = -(float)((short)((rateVect[4] << 8) | rateVect[5]))/15.0;
		rates[1] = -(float)((short)((rateVect[0] << 8) | rateVect[1]))/15.0;
		rates[2] = -(float)((short)((rateVect[2] << 8) | rateVect[3]))/15.0;
	}
	return(err);
}


/******************************************************************************
* Function: getFullScale_max21000
*									
* Read Full Scale value at register *SENSE_CFG0*.				
*  									
* *Type*: Atomic Function							
*									
* Parameter:								
*			none						
*									
* Return: 								
*			0x00 - 2000dps					
*			0x40 - 1000dps					
*			0x80 - 500dps					
*			0xC0 - 250dps					
*									
* See Also:								
*			<Full Scale Constant>				
*									
******************************************************************************/
unsigned char getFullScale_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,FS_REG, &tmpVal);
	return(tmpVal&FS_MSK);
}

/********************************************************
*********************************************************
* Function: setFullScale_max21000					
*								
* Write Full Scale value at register *SENSE_CFG0*.			
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			fullScale - full scale value.			
*								
* Return: 							
*			-1 if communication error occur		
*								
* See Also:							
*			<Full Scale Constant>			
*								
*********************************************************
********************************************************/
signed char setFullScale_max21000(unsigned char fullScale)
{
	signed char err;

#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,FS_REG,MAX21000.channel|MAX21000.powerMode|fullScale);
	if(err > 0)
		MAX21000.fullScale = fullScale;
#else
	err = setParameter(SLAVE_ADD_AMU,FS,fullScale);
#endif

	return(err);
}


/********************************************************
*********************************************************
* Function: getPowerMode_max21000					
*								
* Read the power mode value at register *SENSE_CFG0*.			
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			none					
*								
* Return: 							
*		0x00	- 	DEEP_PD				
*		0x08	- 	NORMAL_MODE			
*		0x18	- 	S>LEEP_MODE			
*		0x30	- 	SLEEP_NORMAL (switching mode on Aux)	
*		0x38	-	DEEP_NORMAL (switching mode on Aux)	
*									
* See Also:								
*			<Power Mode Constant>				
*									
*********************************************************
********************************************************/
unsigned char getPowerMode_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,PW_REG, &tmpVal);
	return(tmpVal&PW_MSK);
}



/********************************************************
*********************************************************
* Function: setPowerMode_max21000					
*								
* Write the Power Mode value at register *SENSE_CFG0*.			
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			powerMode - power Mode value.		
*								
* Return: 							
*			-1 if communication error occur		
*								
* See Also:							
*			<Power Mode Constant>			
*								
*********************************************************
********************************************************/
signed char setPowerMode_max21000(unsigned char powerMode)
{
	signed char err;

//	writeCmd(SLAVE_ADD_AMU,REG_B00_00,powerMode);
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,PW_REG,MAX21000.channel|MAX21000.fullScale|powerMode);
	if(err > 0)
		MAX21000.powerMode = powerMode;
#else
	err = setParameter(SLAVE_ADD_AMU,PW,powerMode);
#endif
	return(err);
}



/********************************************************
*********************************************************
* Function: getDataStatus_max21000					
*								
* Read Status register *STATUS_REG* and return the status of 		
* the data.							
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			none					
*								
* Return: 							
*			00 - No new data				
*			01 - New data available			
*			10 - An error occurred during the read		
*			11 - An error occurred during the read		
*								
* See Also:							
*			<Data status flags>			
*								
*********************************************************
********************************************************/
unsigned char getDataStatus_max21000()
{
	unsigned char status;

	readCmd(SLAVE_ADD_AMU,STATUS_REG, &status);
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	MAX21000.dataStatus = status;
#endif

	return(status);
}


/********************************************************
*********************************************************
* Function: getEnabledRate_max21000					
*								
* Read the setting of Z axe at register *REG_B00_00*.			
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			none					
*								
* Return: 							
*			0x00 - Axe disabled			
*			0x04 - Axe enabled			
*								
* See Also:							
*			<Rate Enable>				
*								
*********************************************************
********************************************************/
unsigned char getEnabledRate_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,RATE_REG, &tmpVal);
	return(tmpVal&RATE_MSK);
}

/********************************************************
*********************************************************
* Function: setEnabledRate_max21000					
*								
* Write Full Scale value at register *SENSE_CFG0*.			
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			enRate - enable for the interesting rate.	
*								
* Return: 							
*			-1 if communication error occur		
*								
* See Also:							
*			<Rate Enable>				
*								
*********************************************************
********************************************************/
signed char setEnabledRate_max21000(unsigned char enRate)
{
	signed char err;
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,RATE_REG,MAX21000.fullScale|MAX21000.powerMode|enRate);
	if(err > 0)
		MAX21000.channel = enRate;
#else
	err = setParameter(SLAVE_ADD_AMU,RATE,enRate);
#endif

	return(err);
}


/********************************************************
*********************************************************
* Function: getDataBw_max21000					
*								
* Read the data Bandwith at register *SENSE_CFG1*.			
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			none					
*								
* Return: 							
*			The bandwith code				
*								
* See Also:							
*			<Bandwidth Constant>			
*								
*********************************************************
********************************************************/
unsigned char getDataBw_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,BW_REG, &tmpVal);
	return(tmpVal&BW_MSK);
}


/********************************************************
* Function: setDataBw_max21000					
*								
* Write the data Bandwith at register *SENSE_CFG1*.			
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			bandwidth - bandwidth value.		
*								
* Return: 							
*			-1 if communication error occur		
*								
* See Also:							
*			<Bandwidth Constant>			
*								
********************************************************/
signed char setDataBw_max21000(unsigned char bandwidth)
{
	signed char err;

#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,BW_REG,MAX21000.maxOdr|MAX21000.oisFullscale|bandwidth);
	if(err > 0)
		MAX21000.bandwidth = bandwidth;
#else
	err = setParameter(SLAVE_ADD_AMU,BW,bandwidth);
#endif

	return(err);
}


/********************************************************
* Function: getMaxFreq_max21000				
*							
* Read the maximum frequency used for the ODR at register	
*  *SENSE_CFG1*.						
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			none				
*							
* Return: 						
*			The configured frequency		
*							
* See Also:						
*			<Max frequency Constant>		
*							
********************************************************/
/*
unsigned char getMaxFreq_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,MAX_ODR_REG, &tmpVal);
	return(tmpVal&MAX_ODR_MSK);
}
*/

/********************************************************
* Function: setMaxFreq_max21000				
*							
* Write the maximum frequency used for the ODR at register	
*  *REG_B00_01*.						
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			maxFreq - 8K or 10K setting value.	
*							
* Return: 						
*			-1 if communication error occur	
*							
* See Also:						
*			<Max frequency Constant>		
*							
********************************************************/
/*
signed char setMaxFreq_max21000(unsigned char maxFreq)
{
	signed char err;

#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,MAX_ODR_REG, MAX21000.bandwidth|MAX21000.oisFullscale|maxFreq);
	if(err > 0)
		MAX21000.maxOdr = maxFreq;
#else
	err = setParameter(SLAVE_ADD_AMU, MAX_ODR, maxFreq);
#endif

	return(err);
}
*/

/********************************************************
* Function: getMaxFreq_max21000				
*							
* Read the OIS full scale configuration at register *SENSE_CFG1*.
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			none				
*							
* Return: 						
*			OIS full scale configuration		
*							
* See Also:						
*			<OIS full scale Constant>		
*							
********************************************************/
unsigned char getOIS_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,OIS_FS_REG, &tmpVal);
	return(tmpVal&OIS_FS_MSK);
}


/********************************************************
* Function: setOIS_max21000					
*								
* Write the OIS full scale configuration at register *SENSE_CFG1*.	
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			oisEn - setting for the ois full scale mode.
*								
* Return: 							
*			-1 if communication error occur		
*								
* See Also:							
*			<OIS full scale Constant>			
*								
********************************************************/
signed char setOIS_max21000(unsigned char oisEn)
{
	signed char err;
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,OIS_FS_REG, MAX21000.bandwidth|MAX21000.maxOdr|oisEn);
	if(err > 0)
		MAX21000.oisFullscale = oisEn;
#else
	err = setParameter(SLAVE_ADD_AMU,OIS_FS,oisEn);
#endif

	return(err);
}


/********************************************************
* Function: getNumericODR_max21000			
*							
* Read the value of the ODR as numeric value at register 		
* *SENSE_CFG2*.						
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			none				
*							
* Return: 						
*			numeric value of the ODR		
*							
* See Also:						
*			<numeric ODR>			
*							
********************************************************/
unsigned char getNumericODR_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,ODR_REG, &tmpVal);
	return(tmpVal&ODR_MSK);
}

/********************************************************
* Function: getODR_max21000					
*								
* Read the value of the ODR at register *SENSE_CFG2* and return 	
* the ODR frequency in Hz.						
*  								
* *Type*: Complex Function						
*								
* Parameter:							
*			maxOdr - value of the max frequency used for ODR
*								
* Return: 							
*			ODR frequency value in Hz			
*								
* See Also:							
*			<numeric ODR>				
*								
*			<Max frequency Constant>			
*								
********************************************************/
float getODR_max21000(unsigned int maxOdr)
{
	unsigned char tmpVal;
	float retOdr;
	tmpVal = getNumericODR_max21000();
	if(tmpVal <= 99)
	{
		retOdr = (float) maxOdr/(tmpVal + 1);
	}
	else if(tmpVal <= 179)
	{
		retOdr = (float) maxOdr/(100 + 5 * (tmpVal - 99));
	}
	else
	{
		retOdr = (float) maxOdr/(500 + 20 * (tmpVal - 179));
	}
	return(retOdr);
}


/********************************************************
* Function: setNumericODR_max21000			
*							
* Write the ODR configuration value at register *SENSE_CFG2*.
*  							
* *Type*: Atomic Function						
*								
* Parameter:							
*			odrVal - output data rate value.		
*								
* Return: 							
*			-1 if communication error occur		
*								
* See Also:							
*			<numeric ODR>				
*								
********************************************************/
signed char setODR_max21000(unsigned char odrVal)
{
	signed char err;

#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,ODR_REG, odrVal);
	if(err > 0)
		MAX21000.odr = odrVal;
#else
	err = setParameter(SLAVE_ADD_AMU,ODR,odrVal);
#endif

	return(err);
}


/********************************************************
* Function: getDataSource_max21000				
*							
* Read the configuration of the digital data chain at register 	
* *SENSE_CFG3* 						
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			none				
*							
* Return: 						
*			Data chain configuration		
*							
* See Also:						
*			<Data source constant>		
*							
********************************************************/
unsigned char getDataSource_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,SRC_CFG_REG, &tmpVal);
	return(tmpVal&SRC_CFG_MSK);
}


/********************************************************
* Function: setDataSource_max21000					
*								
* Write the configuration of the digital data chain at register 		
* *SENSE_CFG3*.							
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			source - data source configuration.		
*								
* Return: 							
*			-1 if communication error occur		
*								
* See Also:							
*			<Data source constant>			
*								
********************************************************/
signed char setDataSource_max21000(unsigned char source)
{
	signed char err;
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU, SRC_CFG_REG, source);
	if(err > 0)
		MAX21000.dataSource = source;
#else
	err = setParameter(SLAVE_ADD_AMU, SRC_CFG, source);
#endif

	return(err);
}


/********************************************************
* Function: getHpCutoff_max21000				
*							
* Read the configuration of the high pass filter cutoff frequency	
* at register *SENSE_CFG3* 					
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			none				
*							
* Return: 						
*			CutOff frequency configuration	
*							
* See Also:						
*			<High pass cut-off constant>	
*							
********************************************************/
unsigned char getHpCutoff_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,HP_CUT_REG, &tmpVal);
	return(tmpVal&HP_CUT_MSK);
}


/********************************************************
* Function: setHpCutoff_max21000				
*							
* Write the configuration of the  high pass filter cutoff frequency at 	
* register *SENSE_CFG3*.					
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			cutOff - cut-off frequency value.	
*							
* Return: 						
*			-1 if communication error occur	
*							
* See Also:						
*			<High pass cut-off constant>	
*							
********************************************************/
signed char setHpCutoff_max21000(unsigned char cutOff)
{
	signed char err;
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,HP_CUT_REG, cutOff);
	if(err > 0)
		MAX21000.hpCutOff = cutOff;
#else
	err = setParameter(SLAVE_ADD_AMU,HP_CUT,cutOff);
#endif

	return(err);
}


/********************************************************
* Function: getEndian_max21000					
*								
* Read the configuration for the big little endian at register 		
* *DR_CFG* 							
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			none					
*								
* Return: 							
*			Big or little endian configuration		
*								
* See Also:							
*			<Endian constant>				
*								
********************************************************/
unsigned char getEndian_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,ENDIAN_REG, &tmpVal);
	return(tmpVal&ENDIAN_MSK);
}


/********************************************************
* Function: setEndian_max21000							
*										
* Write the configuration of the little big endian at 	
* register *DR_CFG*.								
*  										
* *Type*: Atomic Function								
*										
* Parameter:									
*			ble - big little endian value.					
*										
* Return: 									
*			-1 if communication error occur				
*										
* See Also:									
*			<Endian constant>						
*										
********************************************************/
signed char setEndian_max21000(unsigned char ble)
{
	signed char err;
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,ENDIAN_REG, MAX21000.dataReadyRstMode | ble);
	if(err > 0)
		MAX21000.endianMode = ble;
#else
	err = setParameter(SLAVE_ADD_AMU,ENDIAN,ble);
#endif

	return(err);
}

/********************************************************
* Function: getDataReadyRstMode_max21000			
*							
* Read the configuration for the data ready reset mode at register 	
* *DR_CFG* 						
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			none				
*							
* Return: 						
*			data ready reset mode configuration	
*							
* See Also:						
*			<Data ready reset mode constant>	
*							
********************************************************/
unsigned char getDataReadyRstMode_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,DATA_RDY_REG, &tmpVal);
	return(tmpVal&DATA_RDY_MSK);
}


/********************************************************
* Function: setDataReadyRstMode_max21000				
*								
* Write the configuration for the data ready reset mode at 		
* register *DR_CFG*.						
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			drrm - data ready reset mode value.		
*								
* Return: 							
*			-1 if communication error occur		
*								
* See Also:							
*			<Data ready reset mode constant>		
*								
********************************************************/
signed char setDataReadyRstMode_max21000(unsigned char drrm)
{
	signed char err;
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,DATA_RDY_REG, MAX21000.endianMode | drrm);
	if(err > 0)
		MAX21000.dataReadyRstMode = drrm;
#else
	err = setParameter(SLAVE_ADD_AMU,DATA_RDY,drrm);
#endif

	return(err);
}


/********************************************************
* Function: getDsyncPUD_max21000				
*							
* Read the configuration for the pull up and down for DSYNC at 	 
* register *IO_CFG* 					
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			none				
*							
* Return: 						
*			Aux configuration			
*							
* See Also:						
*			<Pull Up/Down constant>		
*							
********************************************************/
unsigned char getDsyncPUD_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,DSYNC_PUD_REG, &tmpVal);
	return(tmpVal&DSYNC_PUD_MSK);
}


/********************************************************
* Function: setDsyncPUD_max21000				
*							
* Write the configuration for the pull up and down for DSYNC at 	 
* register *IO_CFG* 					
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			setPUD - data ready reset mode value.
*							
* Return: 						
*			-1 if communication error occur	
*							
* See Also:						
*			<Pull Up/Down constant>		
*							
********************************************************/
signed char setDsyncPUD_max21000(unsigned char setPUD)
{
	signed char err;
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,DSYNC_PUD_REG, MAX21000.int1PUD | MAX21000.int2PUD | setPUD);
	if(err > 0)
		MAX21000.auxPUD = setPUD;
#else
	err = setParameter(SLAVE_ADD_AMU,DSYNC_PUD,setPUD);
#endif

	return(err);
}

/********************************************************
* Function: getInt1PUD_max21000				
*							
* Read the configuration for the pull up and down for INT1 at 	 
* register *IO_CFG* 					
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			none				
*							
* Return: 						
*			Aux configuration			
*							
* See Also:						
*			<Pull Up/Down constant>		
*							
********************************************************/
unsigned char getInt1PUD_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,INT1_PUD_REG, &tmpVal);
	return(tmpVal&INT1_PUD_MSK);
}


/********************************************************
* Function: setInt1PUD_max21000				
*							
* Write the configuration for the pull up and down for INT1 at 	 
* register *IO_CFG* 					
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			setPUD - data ready reset mode value.
*							
* Return: 						
*			-1 if communication error occur	
*							
* See Also:						
*			<Pull Up/Down constant>		
*							
********************************************************/
signed char setInt1PUD_max21000(unsigned char setPUD)
{
	signed char err;
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,INT1_PUD_REG, MAX21000.auxPUD | MAX21000.int2PUD | setPUD);
	if(err > 0)
		MAX21000.int1PUD = setPUD;
#else
	err = setParameter(SLAVE_ADD_AMU,INT1_PUD,setPUD);
#endif

	return(err);
}

/********************************************************
* Function: getInt2PUD_max21000				
*							
* Read the configuration for the pull up and down for INT1 at 	 
* register *IO_CFG* 					
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			none				
*							
* Return: 						
*			Aux configuration			
*							
* See Also:						
*			<Pull Up/Down constant>		
*							
*********************************************************
********************************************************/
unsigned char getInt2PUD_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,INT2_PUD_REG, &tmpVal);
	return(tmpVal&INT2_PUD_MSK);
}


/********************************************************
* Function: setInt2PUD_max21000				
*							
* Write the configuration for the pull up and down for INT2 at 	 
* register *IO_CFG* 					
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			setPUD - data ready reset mode value.
*							
* Return: 						
*			-1 if communication error occur	
*							
* See Also:						
*			<Pull Up/Down constant>		
*							
********************************************************/
signed char setInt2PUD_max21000(unsigned char setPUD)
{
	signed char err;
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU,INT2_PUD_REG, MAX21000.auxPUD | MAX21000.int1PUD | setPUD);
	if(err > 0)
		MAX21000.int2PUD = setPUD;
#else
	err = setParameter(SLAVE_ADD_AMU, INT2_PUD, setPUD);
#endif

	return(err);
}

/********************************************************
* Function: getI2Cmode_max21000				
*							
* Read the configuration for the I2C interface at register 		
* *I2C_CFG* 						
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			none				
*							
* Return: 						
*			I2C configuration			
*							
* See Also:						
*			<I2C mode constant>		
*							
********************************************************/
unsigned char getI2Cmode_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,I2C_MODE_REG, &tmpVal);
	return(tmpVal&I2C_MODE_MSK);
}


/********************************************************
* Function: setI2Cmode_max21000				
*							
* Write the configuration for the I2C interface at register 		
* *I2C_CFG* 						
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			i2cMode - I2C setting value.		
*							
* Return: 						
*			-1 if communication error occur	
*							
* See Also:						
*			<I2C mode constant>		
*							
********************************************************/
signed char setI2Cmode_max21000(unsigned char i2cMode)
{
	signed char err;
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU, I2C_MODE_REG, MAX21000.padCur| MAX21000.i2cOff | i2cMode);
	if(err > 0)
		MAX21000.i2cMode = i2cMode;
#else
	err = setParameter(SLAVE_ADD_AMU, I2C_MODE, i2cMode);
#endif

	return(err);
}

/********************************************************
* Function: getI2Coff_max21000				
*							
* Read the status of the I2C state machine at register 		
* *I2C_CFG*. I2C can be on or off	.			
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			none				
*							
* Return: 						
*			I2C on/off configuration		
*							
* See Also:						
*			<I2C_OFF>			
*							
********************************************************/
unsigned char getI2Coff_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,I2C_OFF_REG, &tmpVal);
	return(tmpVal&I2C_OFF);
}


/********************************************************
* Function: setI2Coff_max21000				
*							
* Write the status of the I2C state machine at register 		
* *I2C_CFG*. I2C can be on or off	.			
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			i2cOnOff - I2C setting value.		
*							
* Return: 						
*			-1 if communication error occur	
*							
* See Also:						
*			<I2C mode constant>		
*							
********************************************************/
signed char setI2Coff_max21000(unsigned char i2cOnOff)
{
	signed char err;
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU, I2C_OFF_REG, MAX21000.padCur | MAX21000.i2cMode | i2cOnOff);
	if(err > 0)
		MAX21000.i2cOff= i2cOnOff;
#else
	err = setParameter(SLAVE_ADD_AMU, I2C_OFF, i2cOnOff);
#endif

	return(err);
}


/********************************************************
* Function: getPadCurr_max21000				
*							
* Read the pads current configuration at register  *I2C_CFG*.	
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			none				
*							
* Return: 						
*			pads current configuration		
*							
* See Also:						
*			<I2C_OFF>			
*							
********************************************************/
unsigned char getPadCurr_max21000()
{
	unsigned char tmpVal;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	readCmd(SLAVE_ADD_AMU,I2C_OFF_REG, &tmpVal);
	return(tmpVal&I2C_OFF);
}


/********************************************************
* Function: setPadCurr_max21000				
*							
* Write the pads current configuration at register  *I2C_CFG*.	
*  							
* *Type*: Atomic Function					
*							
* Parameter:						
*			padCfg - I2C setting value.		
*							
* Return: 						
*			-1 if communication error occur	
*							
* See Also:						
*			<I2C mode constant>		
*							
********************************************************/
signed char setPadCurr_max21000(unsigned char padCfg)
{
	signed char err;
#ifdef USE_LOCAL
	extern struct localSetting MAX21000;
	changeBank(SLAVE_ADD_AMU,BANK_00);
	err = writeCmd(SLAVE_ADD_AMU, I2C_OFF_REG, MAX21000.i2cOff | MAX21000.i2cMode | padCfg);
	if(err > 0)
		MAX21000.padCur = padCfg;
#else
	err = setParameter(SLAVE_ADD_AMU, I2C_OFF, padCfg);
#endif

	return(err);
}


/********************************************************
* Function: getFifoData_max21000					
*								
* Burst read of FIFO data at register *FIFO_DATA_REG*.			
*  								
* *Type*: Atomic Function						
*								
* Parameter:							
*			numOfData - number of data to read		
*			dataVect    - pointer to the returned read data	
*								
* Return: 							
*			-1 if an error occur				
*								
********************************************************/
signed char getFifoData_max21000(unsigned char numOfData, unsigned char * dataVect)
{
	signed char err = -1;
//	unsigned char warnd;
	unsigned char cnt;
	err = readMultiCmd(SLAVE_ADD_AMU,FIFO_DATA_REG|SINGLE_ADD_BURST, numOfData, dataVect);
	// Workaround for FIFO endian missing and for I2c shifting
	for(cnt=2;cnt<numOfData;cnt+=2)
		*(dataVect+cnt-2) = *(dataVect+cnt);

/*
	// Workaround for FIFO endian missing for SPI
	for(cnt=0;cnt<numOfData;cnt+=2)
	{
		warnd = *(dataVect+cnt);
		*(dataVect+cnt) = *(dataVect+cnt+1);
		*(dataVect+cnt+1) = warnd;
	}
*/
	return(err);
}
