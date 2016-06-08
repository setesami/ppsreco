/** \file
 * 
 *
 * \author Seyed Mohsen Etesami
 */


#include <DataFormats/CTPPSDigi/interface/DiamondDigi.h>


using namespace std;




   DiamondDigi::DiamondDigi (int chid_, int ledt_, int tot_, int trevolt_) 
  {
    chid=chid_;
    ledgt=ledt_;
    tot=tot_;
    trevolt=trevolt_;

  }




    DiamondDigi::DiamondDigi ()
   {
  chid=0;
  ledgt=0;
  tot=0;
  trevolt=0;

   }


  // Comparison
  bool DiamondDigi::operator == (const DiamondDigi& digi) const {if ( chid != digi.getCHID() || ledgt!=digi.getLEDT()||tot != digi.getTOT()||trevolt != digi.getTREVOLT()) return false;
  return true; 
  } 

   // Getters

  int DiamondDigi::getCHID() const{return chid;}
  int DiamondDigi::getLEDT() const{ return ledgt;}
  int DiamondDigi::getTOT() const{ return tot;}
   int DiamondDigi::getTREVOLT() const{ return trevolt;}


  /// Set digi values
  void DiamondDigi::setCHID (int chid_)
   {chid=chid_;}
  void DiamondDigi::setLEDT(int ledt_)
   {ledgt=ledt_;}
  void DiamondDigi::setTOT(int tot_)
   {tot=tot_;}  
void DiamondDigi::setTREVOLT(int trevolt_)
   {trevolt=trevolt_;}



