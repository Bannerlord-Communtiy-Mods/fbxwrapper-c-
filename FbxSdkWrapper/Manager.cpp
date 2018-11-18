#include "stdafx.h"
#include "Manager.h"


using namespace FbxWrapper;

static Manager::Manager()
{
	// Create the FBX SDK memory manager object.
	// The SDK Manager allocates and frees memory
	// for almost all the classes in the SDK.
	m_manager = FbxManager::Create();

	// create an IOSettings object
	FbxIOSettings * ios = FbxIOSettings::Create(m_manager, IOSROOT);
	m_manager->SetIOSettings(ios);


	m_importer = FbxImporter::Create(m_manager, "Importer");
	m_exporter = FbxExporter::Create(m_manager, "Exporter");

	//FbxIOSettings* ios = FbxIOSettings::Create(m_nativeManager, IOSROOT);
	//m_nativeManager->SetIOSettings(ios);

}

FbxManager *Manager::GetInstance()
{
	return m_manager;
}

FbxImporter *Manager::GetImporter()
{
	return m_importer;
}

FbxExporter *Manager::GetExporter()
{
	return m_exporter;
}