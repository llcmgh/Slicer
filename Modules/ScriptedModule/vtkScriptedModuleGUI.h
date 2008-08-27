/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See Doc/copyright/copyright.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkGradientAnisotropicDiffusionFilterGUI.h,v $
  Date:      $Date: 2006/03/19 17:12:29 $
  Version:   $Revision: 1.3 $

=========================================================================auto=*/
#ifndef __vtkScriptedModuleGUI_h
#define __vtkScriptedModuleGUI_h

#include "vtkSlicerBaseGUIWin32Header.h"
#include "vtkSlicerModuleGUI.h"

#include "vtkMRMLScene.h"
#include "vtkScriptedModuleLogic.h"


class VTK_SCRIPTED_EXPORT vtkScriptedModuleGUI : public vtkSlicerModuleGUI
{
public:
  static vtkScriptedModuleGUI *New();
  vtkTypeMacro(vtkScriptedModuleGUI,vtkSlicerModuleGUI);
  void PrintSelf(ostream& os, vtkIndent indent);

   // Description: Get/Set MRML node
  vtkGetObjectMacro (Logic, vtkScriptedModuleLogic);
  vtkSetObjectMacro (Logic, vtkScriptedModuleLogic);
  
  // Description: Get/Set MRML node
  vtkGetObjectMacro (ScriptedModuleNode, vtkMRMLScriptedModuleNode);
  vtkSetObjectMacro (ScriptedModuleNode, vtkMRMLScriptedModuleNode);
  void SetAndObserveScriptedModuleNode (vtkMRMLScriptedModuleNode *n)
    {
    vtkSetAndObserveMRMLNodeMacro( this->ScriptedModuleNode, n);
    }

  // Description:
  // Create widgets
  virtual void BuildGUI ( );

  // Description:
  // Delete Widgets
  virtual void TearDownGUI ( );

  // Description:
  // Add obsereves to GUI widgets
  virtual void AddGUIObservers ( );
  
  // Description:
  // Remove obsereves to GUI widgets
  virtual void RemoveGUIObservers ( );

  // Description:
  // Remove obsereves to MRML node
  virtual void RemoveMRMLNodeObservers ( );

  // Description:
  // Remove obsereves to Logic
  virtual void RemoveLogicObservers ( );
  
  // Description:
  // Pprocess events generated by Logic
  virtual void ProcessLogicEvents ( vtkObject *caller, unsigned long event,
                                  void *callData ){};

  // Description:
  // Pprocess events generated by GUI widgets
  virtual void ProcessGUIEvents ( vtkObject *caller, unsigned long event,
                                  void *callData );

  // Description:
  // Pprocess events generated by MRML
  virtual void ProcessMRMLEvents ( vtkObject *caller, unsigned long event, 
                                  void *callData);
  // Description:
  // Describe behavior at module startup and exit.
  virtual void Enter ( );
  virtual void Exit ( );

  // Description: set an observer by number (work around
  // limitation in kwwidgets tcl wrapping)
  unsigned long AddObserverByNumber (vtkObject *observee, unsigned long event);
  unsigned long AddMRMLObserverByNumber (vtkObject *observee, unsigned long event);
  void RemoveMRMLObserverByNumber (vtkObject *observee, unsigned long event);

  vtkGetMacro(Language,int);
  vtkSetMacro(Language,int);
  void SetLanguageToTcl() { this->SetLanguage(Tcl); }
  void SetLanguageToPython() { this->SetLanguage(Python); }
//BTX
  enum {
    Tcl = 0,
    Python
  };
//ETX

  // Description:
  // Set the category for menu grouping
  vtkSetStringMacro(Category);
  virtual const char *GetCategory() const {return this->Category;};

protected:
  
private:
  vtkScriptedModuleGUI();
  ~vtkScriptedModuleGUI();
  vtkScriptedModuleGUI(const vtkScriptedModuleGUI&);
  void operator=(const vtkScriptedModuleGUI&);

  // Description:
  // Updates GUI widgets based on parameters values in MRML node
  void UpdateGUI();

  // Description:
  // Updates parameters values in MRML node based on GUI widgets 
  void UpdateMRML();
  
  vtkScriptedModuleLogic *Logic;
  vtkMRMLScriptedModuleNode* ScriptedModuleNode;

  int Language;
  char *Category;
};

#endif

