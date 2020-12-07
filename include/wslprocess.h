#ifndef WSLPROCESS_H
#define WSLPROCESS_H

#include "abstractprocess.h"

class WSLProcess : public AbstractProcess {

public:
    WSLProcess();

     QString makeTmpDir();
     void runProcess();
     void compileProcess(QStringList inputFileNames, QString simDelay, QString itPerCycle);
     void stopProcess();
     void copyFiles(QStringList files);

     QString tmpdir;
};

#endif // WSLPROCESS_H
