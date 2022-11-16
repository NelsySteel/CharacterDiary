#include "Tools/XMLProcessor.h"


#include "XmlFile.h"

FXmlFile* XMLProcessor::OpenXMLFile(const FString& fileName)
{
    return new FXmlFile(L"C:/file.xml");
}

FXmlNode* XMLProcessor::GetRootNode(FXmlFile* file)
{
    return file->GetRootNode();
}

TArray<FXmlNode*> XMLProcessor::GetNodeChildren(FXmlNode* node)
{
    return node->GetChildrenNodes();
}

// {
//
//     FXmlNode* RootNode = file->GetRootNode(); // <Your Root Node>
//     TArray<FXmlNode*> ChildNodes = RootNode->GetChildrenNodes();
//     for (FXmlNode* ChildNode : ChildNodes) // Loop for each <Child Node>
//     {
//         // ->GetTag() to get whats inside of <>
//         // ->GetContent() to get whats between <Tag> and </Tag> (e.g. -1350)
//     }
// }