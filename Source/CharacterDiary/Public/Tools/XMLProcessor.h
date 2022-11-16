#pragma once

class FXmlNode;
class FXmlFile;

class XMLProcessor
{
	static FXmlFile* OpenXMLFile(const FString& fileName);
	static FXmlNode* GetRootNode(FXmlFile* file);
	static TArray<FXmlNode*> GetNodeChildren(FXmlNode* node);
};
