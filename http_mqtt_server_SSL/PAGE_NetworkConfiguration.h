

//
//  HTML PAGE
//
const char PAGE_NetCfg[]  PROGMEM = R"=====(
<!DOCTYPE html>
<html>
    <head>
      <title>Configure ESP8266 Wifi</title>
      <style>ADDSTYLE</style>
    </head>
<body>
<hr>
<form id="toesp" action="" method="get">
<table border="0"  cellspacing="0" cellpadding="3" style="width:450px" >
<tr id="headrow"><td colspan="2" align="center"><strong>Internet Connectivity</strong></td></tr>
<tr><td></td></tr><tr><td></td></tr>
<tr><td colspan="2" align="center"><strong>Network Settings</strong></td></tr>
<tr><td align="right">SSID:</td><td><input type="text" id="ssid" name="ssid" value=""></td></tr>
<tr><td align="right">Password:</td><td><input type="text" id="password" name="password" value=""></td></tr>
<tr><td align="right">Server Port:</td><td><input type="text" id="svrport" name="svrport" value=""></td></tr>
<tr><td align="right">IP:     </td><td><input type="text" id="ip_0" name="ip_0" size="3">.<input type="text" id="ip_1" name="ip_1" size="3">.<input type="text" id="ip_2" name="ip_2" size="3">.<input type="text" id="ip_3" name="ip_3" value="" size="3"></td></tr>
<tr><td align="right">Netmask:</td><td><input type="text" id="nm_0" name="nm_0" size="3">.<input type="text" id="nm_1" name="nm_1" size="3">.<input type="text" id="nm_2" name="nm_2" size="3">.<input type="text" id="nm_3" name="nm_3" size="3"></td></tr>
<tr><td align="right">Gateway:</td><td><input type="text" id="gw_0" name="gw_0" size="3">.<input type="text" id="gw_1" name="gw_1" size="3">.<input type="text" id="gw_2" name="gw_2" size="3">.<input type="text" id="gw_3" name="gw_3" size="3"></td></tr>
<tr><td align="right">AP Mode IP:</td><td><input type="text" id="ap_0" name="ap_0" size="3">.<input type="text" id="ap_1" name="ap_1" size="3">.<input type="text" id="ap_2" name="ap_2" size="3">.<input type="text" id="ap_3" name="ap_3" size="3"></td></tr>
<tr><td align="right">FOTA Password:</td><td><input type="text" id="fota_pw" name="fota_pw" value=""></td></tr>
<tr><td align="right">FOTA Port:</td><td><input type="text" id="fota_pt" name="fota_pt" value=""></td></tr>
<tr><td></td></tr><tr><td></td></tr>
<tr><td colspan="2" align="center"><strong>MQTT Settings</strong></td></tr>
<tr><td align="right">Broker:</td><td><input type="text" id="mqtt_bk" name="mqtt_bk" value=""></td></tr>
<tr><td align="right">Port:</td><td><input type="text" id="mqtt_pt" name="mqtt_pt" value=""></td></tr>
<tr><td align="right">ClientId:</td><td><input type="text" id="mqtt_ci" name="mqtt_ci" value=""></td></tr>
<tr><td align="right">User Name:</td><td><input type="text" id="mqtt_un" name="mqtt_un" value=""></td></tr>
<tr><td align="right">Password:</td><td><input type="text" id="mqtt_pw" name="mqtt_pw" value=""></td></tr>
<tr><td align="right">Rx Topic:</td><td><input type="text" id="mqtt_rt" name="mqtt_rt" value=""></td></tr>
<tr><td align="right">Tx Topic:</td><td><input type="text" id="mqtt_tt" name="mqtt_tt" value=""></td></tr>
<tr><td align="right">PW Enable:</td><td><input type="checkbox" id="mqtt_pw_en" name="mqtt_pw_en"></td></tr>
<tr><td align="right">TLS Enable:</td><td><input type="checkbox" id="mqtt_ssl_en" name="mqtt_ssl_en"></td></tr>
<tr><td align="right">MQTT Enable:</td><td><input type="checkbox" id="mqtt_cl_en" name="mqtt_cl_en"></td></tr>
<tr><td></td></tr><tr><td></td></tr>
<tr><td colspan="2" align="center"><strong>Serial Interface</strong></td></tr>
<tr><td align="right">Baud:</td><td><input type="text" id="ser_baud" name="ser_baud" value=""></td></tr>
<tr><td align="right">Arduino Server On:</td><td><input type="checkbox" id="ser_serv" name="ser_serv"></td></tr>
<tr><td></td></tr><tr><td></td></tr>
<tr><td align="right"><input type="submit" style="width:200px" class="btn btn--m btn--blue" value="Save"></td>
<td align="left"><input type="button" style="width:200px" class="btn btn--m btn--blue" value="Reset ESP8266" id="reset" onclick="javascript:ResetEsp();"></td></tr>
</table>
</form>
<hr>
<!-- JavaScript -->
<script>
     document.getElementById('ssid').value = "set_ssid";
     document.getElementById('password').value = "set_pass";
     document.getElementById('ip_0').value = "set_ip0";
     document.getElementById('ip_1').value = "set_ip1";
     document.getElementById('ip_2').value = "set_ip2";
     document.getElementById('ip_3').value = "set_ip3";
     document.getElementById('nm_0').value = "set_nm0";
     document.getElementById('nm_1').value = "set_nm1";
     document.getElementById('nm_2').value = "set_nm2";
     document.getElementById('nm_3').value = "set_nm3";
     document.getElementById('gw_0').value = "set_gw0";
     document.getElementById('gw_1').value = "set_gw1";
     document.getElementById('gw_2').value = "set_gw2";
     document.getElementById('gw_3').value = "set_gw3";
     document.getElementById('ap_0').value = "set_ap0";
     document.getElementById('ap_1').value = "set_ap1";
     document.getElementById('ap_2').value = "set_ap2";
     document.getElementById('ap_3').value = "set_ap3";
     document.getElementById('fota_pw').value = "set_fota_pw";
     document.getElementById('fota_pt').value = "set_fota_pt";
     document.getElementById('svrport').value = "set_port";
     document.getElementById('mqtt_bk').value = "set_bk";
     document.getElementById('mqtt_pt').value = "set_pt";
     document.getElementById('mqtt_ci').value = "set_ci";
     document.getElementById('mqtt_un').value = "set_un";
     document.getElementById('mqtt_pw').value = "set_pw";
     document.getElementById('mqtt_rt').value = "set_rt";
     document.getElementById('mqtt_tt').value = "set_tt";
     document.getElementById('ser_baud').value = "set_baud";
     document.getElementById('ser_serv').checked = set_serv;
     document.getElementById('mqtt_pw_en').checked = set_mqtt_pw_en;
     document.getElementById('mqtt_ssl_en').checked = set_mqtt_ssl_en;
     document.getElementById('mqtt_cl_en').checked = set_mqtt_cl_en;

     function ResetEsp() {
         document.getElementById('ssid').value = "reset";
         document.getElementById("toesp").submit();
      }
</script>
</body>
</html> 
)=====";

const char PAGE_NetCfg2[]  PROGMEM = R"=====(
<!DOCTYPE html>
<html>
    <head>
      <title>Configure ESP8266 Wifi</title>
      <style>ADDSTYLE</style>
    </head>
<body>
<hr>
<form id="toesp" action="" method="get">
<table border="0"  cellspacing="0" cellpadding="3" style="width:450px" >
<tr id="headrow"><td colspan="2" align="center"><strong>Internet Connectivity</strong></td></tr>
<tr><td></td></tr><tr><td></td></tr>
<tr><td colspan="2" align="center"><strong>Network Settings</strong></td></tr>
<tr><td align="right">SSID:</td><td><input type="text" id="ssid" name="ssid" value=""></td></tr>
<tr><td>Will this fit.?</td></tr>
</table>
</form>
</body>
</html> 
)=====";

const char PAGE_WaitAndReload[] PROGMEM = R"=====(
<meta http-equiv="refresh" content="3; URL=config">
Please Wait....Configuring and Restarting.
)=====";

const char PAGE_WaitAndReset[] PROGMEM = R"=====(
<meta http-equiv="refresh" content="1; URL=config">
Please Wait....Reseting ESP8266.
)=====";


 

