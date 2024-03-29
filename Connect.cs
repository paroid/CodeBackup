using System;
using Extensibility;
using EnvDTE;
using EnvDTE80;
using Microsoft.VisualStudio.CommandBars;
using System.Resources;
using System.Reflection;
using System.Globalization;
using System.Windows.Forms;
using System.IO;

namespace MyAddin1
{
	/// <summary>The object for implementing an Add-in.</summary>
	/// <seealso class='IDTExtensibility2' />
    
    

	public class Connect : IDTExtensibility2, IDTCommandTarget
	{

       

		/// <summary>Implements the constructor for the Add-in object. Place your initialization code within this method.</summary>
		public Connect()
		{
		}

		/// <summary>Implements the OnConnection method of the IDTExtensibility2 interface. Receives notification that the Add-in is being loaded.</summary>
		/// <param term='application'>Root object of the host application.</param>
		/// <param term='connectMode'>Describes how the Add-in is being loaded.</param>
		/// <param term='addInInst'>Object representing this Add-in.</param>
		/// <seealso class='IDTExtensibility2' />
		public void OnConnection(object application, ext_ConnectMode connectMode, object addInInst, ref Array custom)
		{
			_applicationObject = (DTE2)application;
			_addInInstance = (AddIn)addInInst;
   
            //custom code
            //System.Windows.Forms.MessageBox.Show(_applicationObject.Solution.FullName+"\n called in OnConnection() !");

			if(connectMode == ext_ConnectMode.ext_cm_UISetup)
            {
				object []contextGUIDS = new object[] { };
				Commands2 commands = (Commands2)_applicationObject.Commands;
				string toolsMenuName;

				try
				{
					//If you would like to move the command to a different menu, change the word "Tools" to the 
					//  English version of the menu. This code will take the culture, append on the name of the menu
					//  then add the command to that menu. You can find a list of all the top-level menus in the file
					//  CommandBar.resx.
					ResourceManager resourceManager = new ResourceManager("MyAddin1.CommandBar", Assembly.GetExecutingAssembly());
					CultureInfo cultureInfo = new System.Globalization.CultureInfo(_applicationObject.LocaleID);
					string resourceName = String.Concat(cultureInfo.TwoLetterISOLanguageName, "Tools");
					toolsMenuName = resourceManager.GetString(resourceName);
				}
				catch
				{
					//We tried to find a localized version of the word Tools, but one was not found.
					//  Default to the en-US word, which may work for the current culture.
					toolsMenuName = "Tools";                    
				}

				//Place the command on the tools menu.
				//Find the MenuBar command bar, which is the top-level command bar holding all the main menu items:
				Microsoft.VisualStudio.CommandBars.CommandBar menuBarCommandBar = ((Microsoft.VisualStudio.CommandBars.CommandBars)_applicationObject.CommandBars)["MenuBar"];

//                 string solName = "Project and Solution Context Menus";
//                 Microsoft.VisualStudio.CommandBars.CommandBar menuBarCommandBar = ((Microsoft.VisualStudio.CommandBars.CommandBars)_applicationObject.CommandBars)[solName];
//                 toolsMenuName = "Add";

				//Find the Tools command bar on the MenuBar command bar:
				CommandBarControl toolsControl = menuBarCommandBar.Controls[toolsMenuName];
				CommandBarPopup toolsPopup = (CommandBarPopup)toolsControl;

                

				//This try/catch block can be duplicated if you wish to add multiple commands to be handled by your Add-in,
				//  just make sure you also update the QueryStatus/Exec method to include the new command names.
				try
				{
					//Add a command to the Commands collection:
					Command command = commands.AddNamedCommand2(_addInInstance, "MyAddin1", "MyAddin1", "Executes the command for MyAddin1", true, 59, ref contextGUIDS, (int)vsCommandStatus.vsCommandStatusSupported+(int)vsCommandStatus.vsCommandStatusEnabled, (int)vsCommandStyle.vsCommandStylePictAndText, vsCommandControlType.vsCommandControlTypeButton);
                    Command command2 = commands.AddNamedCommand2(_addInInstance, "MyAddin1_2", "MyAddin1_2_2", "Executes the command for MyAddin1", true, 59, ref contextGUIDS, (int)vsCommandStatus.vsCommandStatusSupported + (int)vsCommandStatus.vsCommandStatusEnabled, (int)vsCommandStyle.vsCommandStylePictAndText, vsCommandControlType.vsCommandControlTypeButton);



                    CommandBarPopup myPopUp = (CommandBarPopup)menuBarCommandBar.Controls.Add(MsoControlType.msoControlPopup, System.Type.Missing, System.Type.Missing,menuBarCommandBar.Controls.Count + 1, true);
                    myPopUp.CommandBar.Name = "RTI_Menu";
                    myPopUp.Caption = "RTIxx";
                    myPopUp.Visible = true;
					//Add a control for the command to the tools menu:
					if((command != null) && (toolsPopup != null))
					{
						command.AddControl(toolsPopup.CommandBar, 1);
                        command2.AddControl(toolsPopup.CommandBar, 2);
                        command2.AddControl(myPopUp.CommandBar, myPopUp.CommandBar.Controls.Count+1);
					}

                    //add a toolbar
                    CommandBars commandBars = this._applicationObject.CommandBars as CommandBars;        
                    CommandBar commandBar = commandBars["Standard"];        
                    Command command22 = commands.AddNamedCommand2(_addInInstance, "AddToolbar2",
                                "Toolbar Item", "New item for toolbar", true, 59, ref contextGUIDS,
                        (int)vsCommandStatus.vsCommandStatusSupported + (int)vsCommandStatus.vsCommandStatusEnabled,
                        (int)vsCommandStyle.vsCommandStylePictAndText, vsCommandControlType.vsCommandControlTypeButton);        
                    command22.AddControl(commandBar, 1);
                    //end

                    CommandBar SECommandBar = ((CommandBars)_applicationObject.CommandBars)["Context Menus"];
                    CommandBarPopup SEPopUps = (CommandBarPopup)SECommandBar.Controls["Project and Solution Context Menus"];
                    CommandBarPopup ProjectPopUp = (CommandBarPopup)SEPopUps.Controls["Project"];
                    CommandBarPopup addPopUp = (CommandBarPopup)ProjectPopUp.Controls["Add"];
                    CommandBarPopup SolutionPopUp = (CommandBarPopup)SEPopUps.Controls["Solution"];
                    CommandBarPopup ReferencePopUp = (CommandBarPopup)SEPopUps.Controls["Reference Root"];
                    CommandBarPopup ItemPopUp = (CommandBarPopup)SEPopUps.Controls["Item"];

                    Command command33 = commands.AddNamedCommand2(_addInInstance,
        "AddCmd", "AddCmd", "Executes the command for test", true, 59, ref contextGUIDS,
        (int)vsCommandStatus.vsCommandStatusSupported + (int)vsCommandStatus.vsCommandStatusEnabled,
        (int)vsCommandStyle.vsCommandStylePictAndText,
        vsCommandControlType.vsCommandControlTypeButton);
                    /*Command command12 = commands.AddNamedCommand2(_addInInstance,
         "SolutionCmd", "SolutionCmd", "Executes the command for test", true, 59, ref contextGUIDS,
         (int)vsCommandStatus.vsCommandStatusSupported + (int)vsCommandStatus.vsCommandStatusEnabled,
         (int)vsCommandStyle.vsCommandStylePictAndText,
         vsCommandControlType.vsCommandControlTypeButton);*/
                    //You can add more command to different controls.

                    command33.AddControl(ProjectPopUp.CommandBar, 1);
                    command33.AddControl(addPopUp.CommandBar, 1);
                    command33.AddControl(SolutionPopUp.CommandBar, 1);
                    //command33.AddControl(ReferencePopUp.CommandBar, 1);
                    /*command12.AddControl(ItemPopUp.CommandBar, 1);*/



                    //solution explorer
                    MessageBox.Show("Everything seems to be OK!");

				}
				catch(System.ArgumentException)
				{
					//If we are here, then the exception is probably because a command with that name
					//  already exists. If so there is no need to recreate the command and we can 
                    //  safely ignore the exception.
				}
			}
            if (connectMode == ext_ConnectMode.ext_cm_AfterStartup)
            {
               
            }
		}


        /*private void InitializeAddIn()
        {
            CommandBarControl myCommandBarControl;
            CommandBar codeWindowCommandBar;
            Command myCommand1;
            Command myCommand2;
            CommandBars commandBars;

            // Retrieve commands created in the ext_cm_UISetup phase of the OnConnection method
            myCommand1 = m_dte.Commands.Item(m_addIn.ProgID + "." + m_NAME_COMMAND1, -1);
            myCommand2 = m_dte.Commands.Item(m_addIn.ProgID + "." + m_NAME_COMMAND2, -1);

            // Retrieve the context menu of code windows
            commandBars = (CommandBars)m_dte.CommandBars;
            //codeWindowCommandBar = commandBars["Code Window"];
            codeWindowCommandBar = commandBars["Solution"];

            // Add a popup command bar
            myCommandBarControl = codeWindowCommandBar.Controls.Add(MsoControlType.msoControlPopup,
               System.Type.Missing, System.Type.Missing, System.Type.Missing, System.Type.Missing);

            m_commandBarPopup = (CommandBarPopup)myCommandBarControl;

            // Change its caption
            m_commandBarPopup.Caption = "My popup";

            // Add controls to the popup command bar
            m_commandBarControl1 = (CommandBarControl)myCommand1.AddControl(m_commandBarPopup.CommandBar,
               m_commandBarPopup.Controls.Count + 1);

            m_commandBarControl2 = (CommandBarControl)myCommand2.AddControl(m_commandBarPopup.CommandBar,
               m_commandBarPopup.Controls.Count + 1);
        }*/

		/// <summary>Implements the OnDisconnection method of the IDTExtensibility2 interface. Receives notification that the Add-in is being unloaded.</summary>
		/// <param term='disconnectMode'>Describes how the Add-in is being unloaded.</param>
		/// <param term='custom'>Array of parameters that are host application specific.</param>
		/// <seealso class='IDTExtensibility2' />
		public void OnDisconnection(ext_DisconnectMode disconnectMode, ref Array custom)
		{
		}

		/// <summary>Implements the OnAddInsUpdate method of the IDTExtensibility2 interface. Receives notification when the collection of Add-ins has changed.</summary>
		/// <param term='custom'>Array of parameters that are host application specific.</param>
		/// <seealso class='IDTExtensibility2' />		
		public void OnAddInsUpdate(ref Array custom)
		{
		}

		/// <summary>Implements the OnStartupComplete method of the IDTExtensibility2 interface. Receives notification that the host application has completed loading.</summary>
		/// <param term='custom'>Array of parameters that are host application specific.</param>
		/// <seealso class='IDTExtensibility2' />
		public void OnStartupComplete(ref Array custom)
		{
            //custom code
//             CommandBarPopup submenu;
//             try
//             {
//                 object[] contextGUIDS = new object[] { };
//                 Commands2 commands = (Commands2)_applicationObject.Commands;
//                 Microsoft.VisualStudio.CommandBars.CommandBar menuBarCommandBar = ((Microsoft.VisualStudio.CommandBars.CommandBars)_applicationObject.CommandBars)["MenuBar"];
//                 CommandBarControl toolsControl = menuBarCommandBar.Controls["Tools"];
//                 CommandBarPopup toolsPopup = (CommandBarPopup)toolsControl;
//                 //Find the Tools command bar on the MenuBar command bar:
//    
//                 submenu = (CommandBarPopup)toolsPopup.Controls.Add(MsoControlType.msoControlPopup, System.Type.Missing, System.Type.Missing,toolsPopup.Controls.Count + 1, true);
//                 submenu.CommandBar.Name = "SubMenu";
//                 submenu.Caption = "SMenu";
// 
//                 Command cmd = commands.AddNamedCommand2(_addInInstance, "item1", "item1", "Executes the command for MyAddin1", true, 59, ref contextGUIDS, (int)vsCommandStatus.vsCommandStatusSupported + (int)vsCommandStatus.vsCommandStatusEnabled, (int)vsCommandStyle.vsCommandStylePictAndText, vsCommandControlType.vsCommandControlTypeButton);
//                 cmd.AddControl(submenu, 1);
//             }
//             catch (System.Exception ex)
//             {            	
//             }

		}

		/// <summary>Implements the OnBeginShutdown method of the IDTExtensibility2 interface. Receives notification that the host application is being unloaded.</summary>
		/// <param term='custom'>Array of parameters that are host application specific.</param>
		/// <seealso class='IDTExtensibility2' />
		public void OnBeginShutdown(ref Array custom)
		{
		}
		
		/// <summary>Implements the QueryStatus method of the IDTCommandTarget interface. This is called when the command's availability is updated</summary>
		/// <param term='commandName'>The name of the command to determine state for.</param>
		/// <param term='neededText'>Text that is needed for the command.</param>
		/// <param term='status'>The state of the command in the user interface.</param>
		/// <param term='commandText'>Text requested by the neededText parameter.</param>
		/// <seealso class='Exec' />
		public void QueryStatus(string commandName, vsCommandStatusTextWanted neededText, ref vsCommandStatus status, ref object commandText)
		{
			if(neededText == vsCommandStatusTextWanted.vsCommandStatusTextWantedNone)
			{
                switch(commandName){
				    case "MyAddin1.Connect.MyAddin1":				
					    status = (vsCommandStatus)vsCommandStatus.vsCommandStatusSupported|vsCommandStatus.vsCommandStatusEnabled;
					    /*return;*/
                        break;				
                    case "MyAddin1.Connect.MyAddin1_2":                
                        status = (vsCommandStatus)vsCommandStatus.vsCommandStatusSupported | vsCommandStatus.vsCommandStatusEnabled;
                       /* return;*/
                        break;
                    case "MyAddin1.Connect.AddToolbar2":
                        status = (vsCommandStatus)vsCommandStatus.vsCommandStatusSupported | vsCommandStatus.vsCommandStatusEnabled;
                       /* return;*/
                        break;
                    case "MyAddin1.Connect.AddCmd":
                        status = (vsCommandStatus)vsCommandStatus.vsCommandStatusSupported | vsCommandStatus.vsCommandStatusEnabled;
                        break;
                }
			}
		}

		/// <summary>Implements the Exec method of the IDTCommandTarget interface. This is called when the command is invoked.</summary>
		/// <param term='commandName'>The name of the command to execute.</param>
		/// <param term='executeOption'>Describes how the command should be run.</param>
		/// <param term='varIn'>Parameters passed from the caller to the command handler.</param>
		/// <param term='varOut'>Parameters passed from the command handler to the caller.</param>
		/// <param term='handled'>Informs the caller if the command was handled or not.</param>
		/// <seealso class='Exec' />
		public void Exec(string commandName, vsCommandExecOption executeOption, ref object varIn, ref object varOut, ref bool handled)
		{
			handled = false;
			if(executeOption == vsCommandExecOption.vsCommandExecOptionDoDefault)
			{

                //switch(commandName){ ........ }
                switch(commandName){
				    case "MyAddin1.Connect.MyAddin1":				
                        Form1 fm = new Form1();
                        fm.Show();
					    handled = true;
					    /*return;*/
				        break;
                    case "MyAddin1.Connect.MyAddin1_2":
                        MessageBox.Show(" Exec() cmd_MyAddin1_2 !");                   
//                         string res = "";
// 
//                         try
//                         {
//                             int l = ((Microsoft.VisualStudio.CommandBars.CommandBars)_applicationObject.CommandBars).Count;
//                              for (int i = 1; i<l; ++i){
//                                 res += ((Microsoft.VisualStudio.CommandBars.CommandBars)_applicationObject.CommandBars)[i].Name;
//                                 res += "\n";
//                             }
//                         }
//                         catch
//                         {
//                             MessageBox.Show("error");
//                         }
//                         finally
//                         {
//                             //MessageBox.Show(res);
//                             //Console.Write(res);
//                             StreamWriter sw = new StreamWriter("C:/cmd.txt");
//                             sw.Write(res);
//                             sw.Close();
//                         }
                        handled = true;
                        /*return;*/
                        break;
                    case "MyAddin1.Connect.AddToolbar2":
                       //MessageBox.Show("Toolbar item Clicked! ");

                        TextSelection selection =this._applicationObject.ActiveDocument.Selection as TextSelection;
                        MessageBox.Show(selection.Text);

                        handled = true;
                        /*return;*/
                        break;
                    case "MyAddin1.Connect.AddCmd":
                        //MessageBox.Show("Toolbar item Clicked! ");

                        TextSelection selection1 = this._applicationObject.ActiveDocument.Selection as TextSelection;
                        MessageBox.Show(selection1.Text);

                        handled = true;
                        /*return;*/
                        break;
                }
			}
		}
		private DTE2 _applicationObject;
		private AddIn _addInInstance;
	}
}