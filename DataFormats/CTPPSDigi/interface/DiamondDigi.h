#ifndef CTPPSDigi_DiamondDigi_h
#define CTPPSDigi_DiamondDigi_h

/** \class DiamondDigi
 *
 * Digi for PPSTiming.
 *  
 *
 * \author Seyed Mohsen Etesami
 * MArch 2016
 */

#include <boost/cstdint.hpp>

class DiamondDigi{

public:
  
  DiamondDigi (int chid_, int ledt_, int tot_, int trevolt);
  // Default construction.
  
  DiamondDigi ();
  ~DiamondDigi() {};
  

  /// Digis are equal if they are have same chid, ledt and tedt
  bool operator==(const DiamondDigi& digi) const;


  /// Return digi values number
  int getCHID() const;
  int getLEDT() const;
  int getTOT() const;
  int getTREVOLT() const;


  /// Set digi values
  void setCHID (int chid_);
  void setLEDT(int ledt_);  
  void setTOT(int tot_);
  void setTREVOLT(int trevolt_);


  /// Print content of digi
 //   void print() const;

private:

  int chid;
  int ledgt;
  int tot;
  int trevolt;

};


inline bool operator< (const DiamondDigi& one, const DiamondDigi& other)
{
  return one.getCHID() < other.getCHID();
}


  #include<iostream>
  inline std::ostream & operator<<(std::ostream & o, const DiamondDigi& digi) {
  return o << " " << digi.getCHID()
	   << " " << digi.getLEDT()
	   << " " << digi.getTOT()
           << " " << digi.getTREVOLT();
  
}
#endif

