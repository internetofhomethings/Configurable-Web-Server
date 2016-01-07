

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
<tr><td></td></tr><tr><td></td></tr>
<tr><td colspan="2" align="center"><strong>MQTT Settings</strong></td></tr>
<tr><td align="right">MQTT Broker:</td><td><input type="text" id="mqtt_bk" name="mqtt_bk" value=""></td></tr>
<tr><td align="right">MQTT User Name:</td><td><input type="text" id="mqtt_un" name="mqtt_un" value=""></td></tr>
<tr><td align="right">MQTT Password:</td><td><input type="text" id="mqtt_pw" name="mqtt_pw" value=""></td></tr>
<tr><td align="right">MQTT Rx Topic:</td><td><input type="text" id="mqtt_rt" name="mqtt_rt" value=""></td></tr>
<tr><td align="right">MQTT Tx Topic:</td><td><input type="text" id="mqtt_tt" name="mqtt_tt" value=""></td></tr>
<tr><td></td></tr><tr><td></td></tr>
<tr><td colspan="2" align="center"><strong>Serial Interface</strong></td></tr>
<tr><td align="right">Baud:</td><td><input type="text" id="ser_baud" name="ser_baud" value=""></td></tr>
<tr><td align="right">Arduino Server On:</td><td><input type="checkbox" id="ser_serv" name="ser_serv"></td></tr>
<tr><td></td></tr><tr><td></td></tr>
<tr><td align="right"><input type="submit" style="width:200px" class="btn btn--m btn--blue" value="Save"></td>
<td align="left"><input type="button" style="width:200px" class="btn btn--m btn--blue" value="Reset ESP8266" id="reset"></td></tr>
</table>
</form>
<hr>
<!-- jQuery -->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
<script>
     $("#ssid").val("set_ssid");
     $("#password").val("set_pass");
     $("#ip_0").val("set_ip0");
     $("#ip_1").val("set_ip1");
     $("#ip_2").val("set_ip2");
     $("#ip_3").val("set_ip3");
     $("#nm_0").val("set_nm0");
     $("#nm_1").val("set_nm1");
     $("#nm_2").val("set_nm2");
     $("#nm_3").val("set_nm3");
     $("#gw_0").val("set_gw0");
     $("#gw_1").val("set_gw1");
     $("#gw_2").val("set_gw2");
     $("#gw_3").val("set_gw3");
     $("#ap_0").val("set_ap0");
     $("#ap_1").val("set_ap1");
     $("#ap_2").val("set_ap2");
     $("#ap_3").val("set_ap3");
     $("#svrport").val("set_port");
     $("#mqtt_bk").val("set_bk");
     $("#mqtt_un").val("set_un");
     $("#mqtt_pw").val("set_pw");
     $("#mqtt_rt").val("set_rt");
     $("#mqtt_tt").val("set_tt");
     $("#ser_baud").val("set_baud");
     $("#ser_serv").attr("checked", set_serv);
     
     $("#reset").click(function() {
         $("#ssid").val("reset");
         $("#toesp").submit();
     });
</script>
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


 

