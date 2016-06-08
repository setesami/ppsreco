/*
* Author: 
* Seyed Mohsen Etesami 
*/    

#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/Common/interface/DetSet.h"
#include "DataFormats/Common/interface/DetSetVector.h"

#include "DataFormats/CTPPSDigi/interface/DiamondDigi.h"

#include <vector>

namespace {
  namespace {
    DiamondDigi rm_diamo_dig;
    edm::DetSet<DiamondDigi> ds_rp_diamo_dig;
    std::vector<DiamondDigi> vec_rp_diamo_dig;
    edm::DetSetVector<DiamondDigi> dsv_rp_diamo_dig;
    std::vector<edm::DetSet<DiamondDigi> > vec_ds_rp_diamo_dig;
    edm::Wrapper<edm::DetSet<DiamondDigi> > wds_rp_diamo_dig;
    edm::Wrapper<edm::DetSetVector<DiamondDigi> > wdsv_rp_diamo_dig;

  }
}
