#
import FWCore.ParameterSet.Config as cms

process = cms.Process("digiTest")

#process.load("Configuration.StandardSequences.Geometry_cff")
process.load('Configuration.Geometry.GeometryExtended2017Reco_cff')
process.load('Configuration.Geometry.GeometryExtended2017_cff')

process.load("Configuration.StandardSequences.MagneticField_38T_cff")

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:upgrade2017', '')


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.MessageLogger = cms.Service("MessageLogger",
    debugModules = cms.untracked.vstring('PixelDigisTest'),
    destinations = cms.untracked.vstring('cout'),
#    destinations = cms.untracked.vstring("log","cout"),
    cout = cms.untracked.PSet(
        threshold = cms.untracked.string('ERROR')
    )
#    log = cms.untracked.PSet(
#        threshold = cms.untracked.string('DEBUG')
#    )
)

process.source = cms.Source("PoolSource",
    fileNames =  cms.untracked.vstring(
#    'file:/afs/cern.ch/work/d/dkotlins/public/MC/mu/pt100/digis/digis1.root'
#    'file:digis.root'
    'file:digis_nodb.root'
    )
)


process.TFileService = cms.Service("TFileService",
    fileName = cms.string('histo.root')
)

  
process.analysis = cms.EDAnalyzer("PixDigisTest",
    Verbosity = cms.untracked.bool(True),
    phase1 = cms.untracked.bool(True),
# sim in V7
#    src = cms.InputTag("mix"),
# my own pixel only digis
    src = cms.InputTag("simSiPixelDigis"),
# old default
#    src = cms.InputTag("siPixelDigis"),
)

process.p = cms.Path(process.analysis)

