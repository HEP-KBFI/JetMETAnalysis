#include "JetMETAnalysis/JetUtilities/interface/RecoJet.h"

#include "JetMETAnalysis/JetUtilities/interface/GenJet.h" // GenJet

RecoJet::RecoJet(const Jet & jet,
                 Float_t area,
                 Float_t rawFactor,
                 Float_t chHEF,
                 Float_t neHEF,
                 Float_t chEmEF,
                 Float_t neEmEF,
                 Float_t muEF,
                 Float_t hfEF,
                 Float_t hfmEF,
                 Int_t jetId)
  : Jet(jet)
  , area_(area)
  , rawFactor_(rawFactor)
  , chHEF_(chHEF)
  , neHEF_(neHEF)
  , chEmEF_(chEmEF)
  , neEmEF_(neEmEF)
  , muEF_(muEF)
  , hfEF_(hfEF)
  , hfmEF_(hfmEF)
  , jetId_(jetId)
  , genJet_(nullptr)
{}

void
RecoJet::set_genJet(const GenJet * genJet)
{
  genJet_ = genJet;
}

Float_t 
RecoJet::area() const
{
  return area_;
}

Float_t 
RecoJet::rawFactor() const
{
  return rawFactor_;
}
  
Float_t 
RecoJet::chHEF() const
{
  return chHEF_;
}

Float_t 
RecoJet::neHEF() const
{
  return neHEF_;
}

Float_t 
RecoJet::chEmEF() const
{
  return chEmEF_;
}

Float_t 
RecoJet::neEmEF() const
{
  return neEmEF_;
}

Float_t
RecoJet::muEF() const
{
  return muEF_;
}

Float_t
RecoJet::hfEF() const
{
  return hfEF_;
}

Float_t
RecoJet::hfmEF() const
{
  return hfmEF_;
}

Int_t 
RecoJet::jetId() const
{
  return jetId_;
}

const GenJet *
RecoJet::genJet() const
{
  return genJet_;
}

std::ostream &
operator<<(std::ostream & stream,
           const RecoJet & jet)
{ 
  stream << static_cast<const Jet &>(jet)             << ","
            " area = " << jet.area()                   << ","
            " rawFactor = " << jet.rawFactor()         << ","
            " chHEF = " << jet.chHEF()                 << ","
            " neHEF = " << jet.neHEF()                 << ","
            " chEmEF = " << jet.chEmEF()               << ","
            " neEmEF = " << jet.neEmEF()               << ","   
            " muEF = " << jet.muEF()                   << ","
            " hfEF = " << jet.hfEF()                   << ","
            " hfmEF = " << jet.hfmEF()                 << ","
            " jetId = " << jet.jetId()                 << "\n";
  if(jet.genJet())
  {
    stream << "matched to generator-level jet:\n";
    stream << (*jet.genJet());
  } 
  return stream;
}
