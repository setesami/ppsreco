/****************************************************************************
 *
 * This is a part of CT-PPS offline software.
 * Author: 
 *        Seyed Mohsen Etesami
 *        March 2016
 ****************************************************************************/

#ifndef DiamondDetId_h
#define DiamondDetId_h


#include "DataFormats/DetId/interface/DetId.h"
#include <FWCore/Utilities/interface/Exception.h>

#include <iosfwd>
#include <iostream>
#include <string>

/**
 *  PPS  The structure of the raw ID is the following (based on the concept of the DetId)
 *      [28:31] 4 bits Sub-detectors  veryforward=7
 *      [25:27] 2 bits  PPStracking =1 PPSTiming=2  ?what is for diamond??
 * Bit  [24]    1 bit  Arm  1=z>0 0=z<0
 * Bits [22:23] 2 bits Station 0=210m 1=215m(timing) 2=220m
 * Bits [19:21] 3 bits Roman Pot number 0= only RP
 * Bits [13:18] 6 bits Diamond  det number if  sets of Lbars detectors spearatly 0,1,2,..48
 *   Raw means the id included all 32 bit with main sub-detectors and sub-sub-dtectros included


 * There are 3 types of IDs used in CMSSW in the context of RP.
 * \li "class ID" - this class TotemRPDetId, a daughter of DetId
 * \li "raw ID" - unsigned int, the result of rawId() method
 * \li "decimal or symbolic ID" - 4 decimal digit unsigned int, |arm|station|RP|det|
**/

class DiamondDetId : public DetId
{  
 public:
  DiamondDetId();
  
  /// Construct from a raw id. It is required that the Detector part of
  /// id is Totem and the SubDet part is RP, otherwise an exception is thrown.
  explicit DiamondDetId(uint32_t id);
  
  /// Construct from fully qualified identifier.
  DiamondDetId(unsigned int Arm, unsigned int Station,
	     unsigned int RomanPot, unsigned int Detector);
      
  
  inline int Arm() const
    {
      return int((id_>>startArmBit) & 0x1);
    }
  inline int Station() const
    {
      return int((id_>>startStationBit) & 0x3);
    }
  inline int RomanPot() const
    {
      return int((id_>>startRPBit) & 0x7);
    }
  inline int Detector() const
    {
      return int((id_>>startDetBit) & 0x3f); //decimal equ=63
    }

  int RPCopyNumber() const {return RomanPot() + 10*Station() + 100*Arm();}

    
  inline unsigned int DetectorDecId() const
    {
      return Detector()+RomanPot()*10+Station()*100+Arm()*1000;
    }

  //-------------------------------- static members ---------------------------------------

  static const unsigned int startArmBit = 24;
  static const unsigned int startStationBit = 22;
  static const unsigned int startRPBit = 19;
  static const unsigned int startDetBit = 13; 
  static const unsigned int pps_timing_diamond_subdet_id = 5; //need to be asked?


 /// returns true if the raw ID is a PPS-timing one
  static bool Check(unsigned int raw)
  {
    return (((raw >>DetId::kDetOffset) & 0xF) == DetId::VeryForward &&
      ((raw >> DetId::kSubdetOffset) & 0x7) == pps_timing_diamond_subdet_id);
  }





  static unsigned int RawToDecId(unsigned int raw)
    {
      return ((raw >> startArmBit) & 0x1) * 1000 + ((raw >> startStationBit) & 0x3) * 100 +
	((raw >> startRPBit) & 0x7) * 10 + ((raw >> startDetBit) & 0x3f);
    }


  static unsigned int DecToRawId(unsigned int dec)
    {
      unsigned int i = (DetId::VeryForward << DetId::kDetOffset)
        | (pps_timing_diamond_subdet_id << DetId::kSubdetOffset);
      i &= 0xfe000000;
      i |= ((dec % 10) & 0x3f) << startDetBit; dec /= 10;
      i |= ((dec % 10) & 0x7) << startRPBit; dec /= 10;
      i |= ((dec % 10) & 0x3) << startStationBit; dec /= 10;
      i |= ((dec % 10) & 0x1) << startArmBit;
      return i;
    }

  /// returns ID of RP for given detector ID ''i''
  static unsigned int RPOfDet(unsigned int i) { return i / 10; }

  /// returns ID of station for given detector ID ''i''
  static unsigned int StOfDet(unsigned int i) { return i / 100; }

  /// returns ID of arm for given detector ID ''i''
  static unsigned int ArmOfDet(unsigned int i) { return i / 1000; }

  /// returns ID of station for given RP ID ''i''
  static unsigned int StOfRP(unsigned int i) { return i / 10; }

  /// returns ID of arm for given RP ID ''i''
  static unsigned int ArmOfRP(unsigned int i) { return i / 100; }

  /// returns ID of arm for given station ID ''i''
  static unsigned int ArmOfSt(unsigned int i) { return i / 10; }
     
 private:
  inline void init(unsigned int Arm, unsigned int Station, unsigned int RomanPot, unsigned int Detector);
};

std::ostream& operator<<(std::ostream& os, const DiamondDetId& id);

#endif 

