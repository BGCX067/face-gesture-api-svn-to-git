/****************************************************************************
* 
* Copyright (c) 2008 by Yao Wei, all rights reserved.
*
* Author:      	Yao Wei
* Contact:     	njustyw@gmail.com
* 
* This software is partly based on the following open source: 
*  
*		- OpenCV 
* 
****************************************************************************/

#include "AAM_Util.h"

//#ifndef _WINSOCKAPI_
//#include <windows.h>
//#endif

std::ostream& operator<<(std::ostream &os, const CvMat* mat)
{
	for(int i = 0; i < mat->rows; i++)
	{
		for(int j = 0; j < mat->cols; j++)
		{
			os << CV_MAT_ELEM(*mat, double, i, j) << " ";
		}
		os << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream &is, CvMat* mat)
{
	for(int i = 0; i < mat->rows; i++)
	{
		for(int j = 0; j < mat->cols; j++)
		{
			is >> CV_MAT_ELEM(*mat, double, i, j);
		}
	}
	return is;
}

// compare function for the qsort() call below
static int str_compare(const void *arg1, const void *arg2)
{
    return strcmp((*(std::string*)arg1).c_str(), (*(std::string*)arg2).c_str());
}


/*std::vector<std::string> ScanNSortDirectory(const std::string &path, 
											const std::string &extension)
{
    WIN32_FIND_DATA wfd;
    HANDLE hHandle;
    std::string searchPath, searchFile;
    std::vector<std::string> vFilenames;
	int nbFiles = 0;
    
	searchPath = path + "/*" + extension;
	hHandle = FindFirstFile(searchPath.c_str(), &wfd);
	if (INVALID_HANDLE_VALUE == hHandle)
    {
        fprintf(stderr, "ERROR(%s, %d): Can not find (*.%s)files in directory %s\n",
			__FILE__, __LINE__, extension.c_str(), path.c_str());
		exit(0);
    }
    do
    {
        //. or ..
        if (wfd.cFileName[0] == '.')
        {
            continue;
        }
        // if exists sub-directory
        if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            continue;
	    }
        else//if file
        {
			searchFile = path + "/" + wfd.cFileName;
			vFilenames.push_back(searchFile);
			nbFiles++;
		}
    }while (FindNextFile(hHandle, &wfd));

    FindClose(hHandle);

	// sort the filenames
    qsort((void *)&(vFilenames[0]), (size_t)nbFiles, sizeof(std::string), str_compare);

    return vFilenames;
}*/

AAM::AAM()
{
}

AAM::~AAM()
{
}