#ifndef SiPixelRecHitsValid_pix_h
#define SiPixelRecHitsValid_pix_h

/** \class SiPixelRecHitsValid
 * File: SiPixelRecHitsValid.h
 * \author Jason Shaev, JHU
 * Created: 6/7/06
 */

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "DataFormats/Common/interface/Handle.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Utilities/interface/InputTag.h"

//Simhit stuff
#include "SimDataFormats/TrackingHit/interface/PSimHit.h"
#include "SimTracker/TrackerHitAssociation/interface/TrackerHitAssociator.h"

#include "DataFormats/SiPixelCluster/interface/SiPixelCluster.h"
#include "DataFormats/TrackerRecHit2D/interface/SiPixelRecHitCollection.h"
#include "DataFormats/DetId/interface/DetId.h"

#include "Geometry/CommonTopologies/interface/PixelTopology.h"
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetUnit.h"
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetType.h"
#include "Geometry/CommonDetUnit/interface/GeomDetType.h"
#include "Geometry/CommonDetUnit/interface/GeomDetUnit.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/TrackerNumberingBuilder/interface/GeometricDet.h"

//DWM histogram services
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"

#include <string>

class TrackerTopology;

class SiPixelRecHitsValid_pix : public edm::EDAnalyzer {

   public:
	//Constructor
	SiPixelRecHitsValid_pix(const edm::ParameterSet& conf);

	//Destructor
	~SiPixelRecHitsValid_pix();

   protected:

	virtual void analyze(const edm::Event& e, const edm::EventSetup& c);
	void beginJob();
	void endJob();

   private:
	DQMStore* dbe_;
	std::string outputFile_;

	edm::ParameterSet conf_;

	void fillBarrel(const SiPixelRecHit &,const PSimHit &, DetId, const PixelGeomDetUnit *,	
			 const TrackerTopology *tTopo);
	void fillForward(const SiPixelRecHit &, const PSimHit &, DetId, const PixelGeomDetUnit *,
			 const TrackerTopology *tTopo);

	//Clusters BPIX
	MonitorElement* clustYSizeModule[8];
	MonitorElement* clustXSizeLayer[4];
	MonitorElement* clustChargeLayer1Modules[8];
	MonitorElement* clustChargeLayer2Modules[8];
	MonitorElement* clustChargeLayer3Modules[8];
	MonitorElement* clustChargeLayer4Modules[8];

	//Cluster FPIX
	MonitorElement* clustXSizeDisk1Plaquettes[7];
	MonitorElement* clustXSizeDisk2Plaquettes[7];
	MonitorElement* clustXSizeDisk3Plaquettes[7];
	MonitorElement* clustYSizeDisk1Plaquettes[7];
	MonitorElement* clustYSizeDisk2Plaquettes[7];
	MonitorElement* clustYSizeDisk3Plaquettes[7];
	MonitorElement* clustChargeDisk1Plaquettes[7];
	MonitorElement* clustChargeDisk2Plaquettes[7];
	MonitorElement* clustChargeDisk3Plaquettes[7];

	//RecHits BPIX
	MonitorElement* recHitXResAllB;
	MonitorElement* recHitYResAllB;
	MonitorElement* recHitXFullModules;
	MonitorElement* recHitXHalfModules;
	MonitorElement* recHitYAllModules;
	MonitorElement* recHitXResFlippedLadderLayers[4];
	MonitorElement* recHitXResNonFlippedLadderLayers[4];
	MonitorElement* recHitYResLayer1Modules[8];
	MonitorElement* recHitYResLayer2Modules[8];
	MonitorElement* recHitYResLayer3Modules[8];
	MonitorElement* recHitYResLayer4Modules[8];

	MonitorElement* recHitXResLayers[4];
	MonitorElement* recHitYResLayers[4];
	MonitorElement* recHitXResLayersP[4];
	MonitorElement* recHitYResLayersP[4];
	MonitorElement* recHitXResLayersP1[4];
	MonitorElement* recHitXResLayersP2[4];
	MonitorElement* recHitXResLayersP3[4];
	MonitorElement* recHitYResLayersP1[4];
	MonitorElement* recHitYResLayersP2[4];
	MonitorElement* recHitYResLayersP3[4];
	MonitorElement* recHitYResLayersP4[4];
	MonitorElement* recHitXResLayer1Eta[25];
	MonitorElement* recHitXResLayer2Eta[25];
	MonitorElement* recHitXResLayer3Eta[25];
	MonitorElement* recHitYResLayer1Eta[25];
	MonitorElement* recHitYResLayer2Eta[25];
	MonitorElement* recHitYResLayer3Eta[25];
	MonitorElement* heta;
	MonitorElement* heta1;
	MonitorElement* heta2;
	MonitorElement* heta3;
	MonitorElement* htest1;
	MonitorElement* htest2;
	MonitorElement* htest3;


	//RecHits FPIX
	MonitorElement* recHitXResAllF;
	MonitorElement* recHitYResAllF;
	//MonitorElement* recHitXPlaquetteSize1;
	//MonitorElement* recHitXPlaquetteSize2;
	//MonitorElement* recHitYPlaquetteSize2;
	//MonitorElement* recHitYPlaquetteSize3;
	//MonitorElement* recHitYPlaquetteSize4;
	//MonitorElement* recHitYPlaquetteSize5;
	MonitorElement* recHitXResDisk1[7];
	MonitorElement* recHitYResDisk1[7];
	MonitorElement* recHitXResDisk2[7];
	MonitorElement* recHitYResDisk2[7];
	MonitorElement* recHitXResDisk3[7];
	MonitorElement* recHitYResDisk3[7];

	// Pull distributions
	//RecHits BPIX
	MonitorElement* recHitXPullAllB;
	MonitorElement* recHitYPullAllB;
	MonitorElement *recHitXError1B,*recHitXError2B,*recHitXError3B,*recHitXError4B;
	MonitorElement *recHitYError1B,*recHitYError2B,*recHitYError3B,*recHitYError4B;

	MonitorElement* recHitXPullFlippedLadderLayers[4];
	MonitorElement* recHitXPullNonFlippedLadderLayers[4];
	MonitorElement* recHitYPullLayer1Modules[8];
	MonitorElement* recHitYPullLayer2Modules[8];
	MonitorElement* recHitYPullLayer3Modules[8];
	MonitorElement* recHitYPullLayer4Modules[8];

	//RecHits FPIX
	MonitorElement* recHitXPullAllF;
	MonitorElement* recHitYPullAllF;
	MonitorElement* recHitXErrorAllF;
	MonitorElement* recHitYErrorAllF;

	MonitorElement* recHitXPullDisk1Plaquettes[7];
	MonitorElement* recHitYPullDisk1Plaquettes[7];
	MonitorElement* recHitXPullDisk2Plaquettes[7];
	MonitorElement* recHitYPullDisk2Plaquettes[7];
	MonitorElement* recHitXPullDisk3Plaquettes[7];
	MonitorElement* recHitYPullDisk3Plaquettes[7];

	// Alignment errors 
	MonitorElement *recHitXAlignError1, *recHitXAlignError2, *recHitXAlignError3;
	MonitorElement *recHitXAlignError4, *recHitXAlignError5, *recHitXAlignError6, *recHitXAlignError7;
	MonitorElement *recHitYAlignError1, *recHitYAlignError2, *recHitYAlignError3;
	MonitorElement *recHitYAlignError4, *recHitYAlignError5, *recHitYAlignError6, *recHitYAlignError7;

	MonitorElement* test;

        edm::InputTag src_;
};

#endif
