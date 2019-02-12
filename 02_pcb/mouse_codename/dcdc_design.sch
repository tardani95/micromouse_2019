<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.3.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="SamacSys_Parts">
<description>&lt;b&gt;https://componentsearchengine.com&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by SamacSys&lt;/author&gt;</description>
<packages>
<package name="SON65P280X300X133-9T110X190" urn="urn:adsk.eagle:footprint:8852124/1">
<description>8-SON, 0.65 mm pitch, 3.00 X 2.80 X 1.33 mm body, 1.90 X 1.10 mm thermal pad
&lt;p&gt;8-pin SON package with 0.65 mm pitch with body size 3.00 X 2.80 X 1.33 mm and thermal pad size 1.90 X 1.10 mm&lt;/p&gt;</description>
<circle x="-1.954" y="1.6884" radius="0.25" width="0" layer="21"/>
<wire x1="-1.45" y1="1.4384" x2="-1.45" y2="1.55" width="0.12" layer="21"/>
<wire x1="-1.45" y1="1.55" x2="1.45" y2="1.55" width="0.12" layer="21"/>
<wire x1="1.45" y1="1.55" x2="1.45" y2="1.4384" width="0.12" layer="21"/>
<wire x1="-1.45" y1="-1.4384" x2="-1.45" y2="-1.55" width="0.12" layer="21"/>
<wire x1="-1.45" y1="-1.55" x2="1.45" y2="-1.55" width="0.12" layer="21"/>
<wire x1="1.45" y1="-1.55" x2="1.45" y2="-1.4384" width="0.12" layer="21"/>
<wire x1="1.45" y1="-1.55" x2="-1.45" y2="-1.55" width="0.12" layer="51"/>
<wire x1="-1.45" y1="-1.55" x2="-1.45" y2="1.55" width="0.12" layer="51"/>
<wire x1="-1.45" y1="1.55" x2="1.45" y2="1.55" width="0.12" layer="51"/>
<wire x1="1.45" y1="1.55" x2="1.45" y2="-1.55" width="0.12" layer="51"/>
<smd name="1" x="-1.2993" y="0.975" dx="0.9306" dy="0.4187" layer="1"/>
<smd name="2" x="-1.2993" y="0.325" dx="0.9306" dy="0.4187" layer="1"/>
<smd name="3" x="-1.2993" y="-0.325" dx="0.9306" dy="0.4187" layer="1"/>
<smd name="4" x="-1.2993" y="-0.975" dx="0.9306" dy="0.4187" layer="1"/>
<smd name="5" x="1.2993" y="-0.975" dx="0.9306" dy="0.4187" layer="1"/>
<smd name="6" x="1.2993" y="-0.325" dx="0.9306" dy="0.4187" layer="1"/>
<smd name="7" x="1.2993" y="0.325" dx="0.9306" dy="0.4187" layer="1"/>
<smd name="8" x="1.2993" y="0.975" dx="0.9306" dy="0.4187" layer="1"/>
<smd name="9" x="0" y="0" dx="1.1" dy="1.9" layer="1" thermals="no"/>
<text x="0" y="2.5734" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<text x="0" y="-2.185" size="1.27" layer="27" align="top-center">&gt;VALUE</text>
</package>
<package name="QFP50P1200X1200X160-64" urn="urn:adsk.eagle:footprint:8852263/1" locally_modified="yes">
<description>64-QFP, 0.50 mm pitch, 12.00 mm span, 10.00 X 10.00 X 1.60 mm body
&lt;p&gt;64-pin QFP package with 0.50 mm pitch, 12.00 mm lead span1 X 12.00 mm lead span2 with body size 10.00 X 10.00 X 1.60 mm&lt;/p&gt;</description>
<circle x="-5.703" y="4.394" radius="0.25" width="0" layer="21"/>
<wire x1="-5" y1="4.144" x2="-5" y2="5" width="0.12" layer="21"/>
<wire x1="-5" y1="5" x2="-4.144" y2="5" width="0.12" layer="21"/>
<wire x1="5" y1="4.144" x2="5" y2="5" width="0.12" layer="21"/>
<wire x1="5" y1="5" x2="4.144" y2="5" width="0.12" layer="21"/>
<wire x1="5" y1="-4.144" x2="5" y2="-5" width="0.12" layer="21"/>
<wire x1="5" y1="-5" x2="4.144" y2="-5" width="0.12" layer="21"/>
<wire x1="-5" y1="-4.144" x2="-5" y2="-5" width="0.12" layer="21"/>
<wire x1="-5" y1="-5" x2="-4.144" y2="-5" width="0.12" layer="21"/>
<wire x1="5" y1="-5" x2="-5" y2="-5" width="0.12" layer="51"/>
<wire x1="-5" y1="-5" x2="-5" y2="5" width="0.12" layer="51"/>
<wire x1="-5" y1="5" x2="5" y2="5" width="0.12" layer="51"/>
<wire x1="5" y1="5" x2="5" y2="-5" width="0.12" layer="51"/>
<smd name="1" x="-5.6713" y="3.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="2" x="-5.6713" y="3.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="3" x="-5.6713" y="2.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="4" x="-5.6713" y="2.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="5" x="-5.6713" y="1.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="6" x="-5.6713" y="1.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="7" x="-5.6713" y="0.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="8" x="-5.6713" y="0.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="9" x="-5.6713" y="-0.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="10" x="-5.6713" y="-0.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="11" x="-5.6713" y="-1.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="12" x="-5.6713" y="-1.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="13" x="-5.6713" y="-2.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="14" x="-5.6713" y="-2.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="15" x="-5.6713" y="-3.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="16" x="-5.6713" y="-3.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="17" x="-3.75" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="18" x="-3.25" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="19" x="-2.75" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="20" x="-2.25" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="21" x="-1.75" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="22" x="-1.25" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="23" x="-0.75" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="24" x="-0.25" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="25" x="0.25" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="26" x="0.75" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="27" x="1.25" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="28" x="1.75" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="29" x="2.25" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="30" x="2.75" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="31" x="3.25" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="32" x="3.75" y="-5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="33" x="5.6713" y="-3.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="34" x="5.6713" y="-3.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="35" x="5.6713" y="-2.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="36" x="5.6713" y="-2.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="37" x="5.6713" y="-1.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="38" x="5.6713" y="-1.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="39" x="5.6713" y="-0.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="40" x="5.6713" y="-0.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="41" x="5.6713" y="0.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="42" x="5.6713" y="0.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="43" x="5.6713" y="1.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="44" x="5.6713" y="1.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="45" x="5.6713" y="2.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="46" x="5.6713" y="2.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="47" x="5.6713" y="3.25" dx="1.4692" dy="0.28" layer="1"/>
<smd name="48" x="5.6713" y="3.75" dx="1.4692" dy="0.28" layer="1"/>
<smd name="49" x="3.75" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="50" x="3.25" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="51" x="2.75" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="52" x="2.25" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="53" x="1.75" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="54" x="1.25" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="55" x="0.75" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="56" x="0.25" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="57" x="-0.25" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="58" x="-0.75" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="59" x="-1.25" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="60" x="-1.75" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="61" x="-2.25" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="62" x="-2.75" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="63" x="-3.25" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<smd name="64" x="-3.75" y="5.6713" dx="1.4692" dy="0.28" layer="1" rot="R90"/>
<text x="0" y="1.9609" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<text x="0" y="-1.9609" size="1.27" layer="27" align="top-center">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="SON65P280X300X133-9T110X190" urn="urn:adsk.eagle:package:8852109/1" type="model">
<description>8-SON, 0.65 mm pitch, 3.00 X 2.80 X 1.33 mm body, 1.90 X 1.10 mm thermal pad
&lt;p&gt;8-pin SON package with 0.65 mm pitch with body size 3.00 X 2.80 X 1.33 mm and thermal pad size 1.90 X 1.10 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="SON65P280X300X133-9T110X190"/>
</packageinstances>
</package3d>
<package3d name="QFP50P1200X1200X160-64" urn="urn:adsk.eagle:package:8852219/1" locally_modified="yes" type="model">
<description>64-QFP, 0.50 mm pitch, 12.00 mm span, 10.00 X 10.00 X 1.60 mm body
&lt;p&gt;64-pin QFP package with 0.50 mm pitch, 12.00 mm lead span1 X 12.00 mm lead span2 with body size 10.00 X 10.00 X 1.60 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="QFP50P1200X1200X160-64"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="TPS82085SILR">
<wire x1="5.08" y1="2.54" x2="25.4" y2="2.54" width="0.254" layer="94"/>
<wire x1="25.4" y1="-27.94" x2="25.4" y2="2.54" width="0.254" layer="94"/>
<wire x1="25.4" y1="-27.94" x2="5.08" y2="-27.94" width="0.254" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-27.94" width="0.254" layer="94"/>
<text x="26.67" y="7.62" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="26.67" y="5.08" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="EN" x="0" y="0" length="middle" direction="in"/>
<pin name="PG" x="0" y="-2.54" length="middle" direction="out"/>
<pin name="VIN_1" x="0" y="-5.08" length="middle" direction="pwr"/>
<pin name="VIN_2" x="0" y="-7.62" length="middle" direction="pwr"/>
<pin name="THERMAL_PAD" x="15.24" y="-33.02" length="middle" rot="R90"/>
<pin name="VOUT" x="30.48" y="0" length="middle" direction="pwr" rot="R180"/>
<pin name="FB" x="30.48" y="-2.54" length="middle" direction="in" rot="R180"/>
<pin name="GND_2" x="30.48" y="-5.08" length="middle" direction="pwr" rot="R180"/>
<pin name="GND_1" x="30.48" y="-7.62" length="middle" direction="pwr" rot="R180"/>
</symbol>
<symbol name="STM32F405RGT6">
<wire x1="5.08" y1="12.7" x2="48.26" y2="12.7" width="0.254" layer="94"/>
<wire x1="48.26" y1="-50.8" x2="48.26" y2="12.7" width="0.254" layer="94"/>
<wire x1="48.26" y1="-50.8" x2="5.08" y2="-50.8" width="0.254" layer="94"/>
<wire x1="5.08" y1="12.7" x2="5.08" y2="-50.8" width="0.254" layer="94"/>
<text x="49.53" y="17.78" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="49.53" y="15.24" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="VBAT" x="0" y="0" length="middle"/>
<pin name="PC13" x="0" y="-2.54" length="middle"/>
<pin name="PC14" x="0" y="-5.08" length="middle"/>
<pin name="PC15" x="0" y="-7.62" length="middle"/>
<pin name="PH0" x="0" y="-10.16" length="middle"/>
<pin name="PH1" x="0" y="-12.7" length="middle"/>
<pin name="NRST" x="0" y="-15.24" length="middle" direction="in"/>
<pin name="PC0" x="0" y="-17.78" length="middle"/>
<pin name="PC1" x="0" y="-20.32" length="middle"/>
<pin name="PC2" x="0" y="-22.86" length="middle"/>
<pin name="PC3" x="0" y="-25.4" length="middle"/>
<pin name="VSSA" x="0" y="-27.94" length="middle" direction="pwr"/>
<pin name="VDDA" x="0" y="-30.48" length="middle" direction="pwr"/>
<pin name="PA0_WKUP" x="0" y="-33.02" length="middle"/>
<pin name="PA1" x="0" y="-35.56" length="middle"/>
<pin name="PA2" x="0" y="-38.1" length="middle"/>
<pin name="PA3" x="7.62" y="-55.88" length="middle" rot="R90"/>
<pin name="VSS_1" x="10.16" y="-55.88" length="middle" direction="pwr" rot="R90"/>
<pin name="VDD_1" x="12.7" y="-55.88" length="middle" direction="pwr" rot="R90"/>
<pin name="PA4" x="15.24" y="-55.88" length="middle" rot="R90"/>
<pin name="PA5" x="17.78" y="-55.88" length="middle" rot="R90"/>
<pin name="PA6" x="20.32" y="-55.88" length="middle" rot="R90"/>
<pin name="PA7" x="22.86" y="-55.88" length="middle" rot="R90"/>
<pin name="PC4" x="25.4" y="-55.88" length="middle" rot="R90"/>
<pin name="PC5" x="27.94" y="-55.88" length="middle" rot="R90"/>
<pin name="PB0" x="30.48" y="-55.88" length="middle" rot="R90"/>
<pin name="PB1" x="33.02" y="-55.88" length="middle" rot="R90"/>
<pin name="PB2" x="35.56" y="-55.88" length="middle" rot="R90"/>
<pin name="PB10" x="38.1" y="-55.88" length="middle" rot="R90"/>
<pin name="PB11" x="40.64" y="-55.88" length="middle" rot="R90"/>
<pin name="VCAP_1" x="43.18" y="-55.88" length="middle" rot="R90"/>
<pin name="VDD_2" x="45.72" y="-55.88" length="middle" direction="pwr" rot="R90"/>
<pin name="VDD_3" x="53.34" y="0" length="middle" direction="pwr" rot="R180"/>
<pin name="VCAP_2" x="53.34" y="-2.54" length="middle" rot="R180"/>
<pin name="PA13" x="53.34" y="-5.08" length="middle" rot="R180"/>
<pin name="PA12" x="53.34" y="-7.62" length="middle" rot="R180"/>
<pin name="PA11" x="53.34" y="-10.16" length="middle" rot="R180"/>
<pin name="PA10" x="53.34" y="-12.7" length="middle" rot="R180"/>
<pin name="PA9" x="53.34" y="-15.24" length="middle" rot="R180"/>
<pin name="PA8" x="53.34" y="-17.78" length="middle" rot="R180"/>
<pin name="PC9" x="53.34" y="-20.32" length="middle" rot="R180"/>
<pin name="PC8" x="53.34" y="-22.86" length="middle" rot="R180"/>
<pin name="PC7" x="53.34" y="-25.4" length="middle" rot="R180"/>
<pin name="PC6" x="53.34" y="-27.94" length="middle" rot="R180"/>
<pin name="PB15" x="53.34" y="-30.48" length="middle" rot="R180"/>
<pin name="PB14" x="53.34" y="-33.02" length="middle" rot="R180"/>
<pin name="PB13" x="53.34" y="-35.56" length="middle" rot="R180"/>
<pin name="PB12" x="53.34" y="-38.1" length="middle" rot="R180"/>
<pin name="VDD_4" x="7.62" y="17.78" length="middle" direction="pwr" rot="R270"/>
<pin name="VSS_2" x="10.16" y="17.78" length="middle" direction="pwr" rot="R270"/>
<pin name="PB9" x="12.7" y="17.78" length="middle" rot="R270"/>
<pin name="PB8" x="15.24" y="17.78" length="middle" rot="R270"/>
<pin name="BOOT0" x="17.78" y="17.78" length="middle" rot="R270"/>
<pin name="PB7" x="20.32" y="17.78" length="middle" rot="R270"/>
<pin name="PB6" x="22.86" y="17.78" length="middle" rot="R270"/>
<pin name="PB5" x="25.4" y="17.78" length="middle" rot="R270"/>
<pin name="PB4" x="27.94" y="17.78" length="middle" rot="R270"/>
<pin name="PB3" x="30.48" y="17.78" length="middle" rot="R270"/>
<pin name="PD2" x="33.02" y="17.78" length="middle" rot="R270"/>
<pin name="PC12" x="35.56" y="17.78" length="middle" rot="R270"/>
<pin name="PC11" x="38.1" y="17.78" length="middle" rot="R270"/>
<pin name="PC10" x="40.64" y="17.78" length="middle" rot="R270"/>
<pin name="PA15" x="43.18" y="17.78" length="middle" rot="R270"/>
<pin name="PA14" x="45.72" y="17.78" length="middle" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="TPS82085SILR" prefix="PS">
<description>&lt;b&gt;TEXAS INSTRUMENTS - TPS82085SILR - DC/DC CONV, SYNC BUCK, 2.4MHZ, USIP-8&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="https://mouser.componentsearchengine.com/Datasheets/2/TPS82085SILR.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="TPS82085SILR" x="0" y="0"/>
</gates>
<devices>
<device name="SON65P280X300X133-9T" package="SON65P280X300X133-9T110X190">
<connects>
<connect gate="G$1" pin="EN" pad="1"/>
<connect gate="G$1" pin="FB" pad="7"/>
<connect gate="G$1" pin="GND_1" pad="5"/>
<connect gate="G$1" pin="GND_2" pad="6"/>
<connect gate="G$1" pin="PG" pad="2"/>
<connect gate="G$1" pin="THERMAL_PAD" pad="9"/>
<connect gate="G$1" pin="VIN_1" pad="3"/>
<connect gate="G$1" pin="VIN_2" pad="4"/>
<connect gate="G$1" pin="VOUT" pad="8"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8852109/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="STM32F405RGT6" prefix="IC">
<description>&lt;b&gt;MCU 32-Bit, ARM Cortex M4, 1MB Flash STMicroelectronics STM32F405RGT6, 32bit ARM Cortex M4F Microcontroller, 168MHz, 1024 kB Flash, 64-Pin LQFP&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://www.mouser.com/datasheet/2/389/stm32f405rg-956214.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="STM32F405RGT6" x="0" y="0"/>
</gates>
<devices>
<device name="LQFP64" package="QFP50P1200X1200X160-64">
<connects>
<connect gate="G$1" pin="BOOT0" pad="60"/>
<connect gate="G$1" pin="NRST" pad="7"/>
<connect gate="G$1" pin="PA0_WKUP" pad="14"/>
<connect gate="G$1" pin="PA1" pad="15"/>
<connect gate="G$1" pin="PA10" pad="43"/>
<connect gate="G$1" pin="PA11" pad="44"/>
<connect gate="G$1" pin="PA12" pad="45"/>
<connect gate="G$1" pin="PA13" pad="46"/>
<connect gate="G$1" pin="PA14" pad="49"/>
<connect gate="G$1" pin="PA15" pad="50"/>
<connect gate="G$1" pin="PA2" pad="16"/>
<connect gate="G$1" pin="PA3" pad="17"/>
<connect gate="G$1" pin="PA4" pad="20"/>
<connect gate="G$1" pin="PA5" pad="21"/>
<connect gate="G$1" pin="PA6" pad="22"/>
<connect gate="G$1" pin="PA7" pad="23"/>
<connect gate="G$1" pin="PA8" pad="41"/>
<connect gate="G$1" pin="PA9" pad="42"/>
<connect gate="G$1" pin="PB0" pad="26"/>
<connect gate="G$1" pin="PB1" pad="27"/>
<connect gate="G$1" pin="PB10" pad="29"/>
<connect gate="G$1" pin="PB11" pad="30"/>
<connect gate="G$1" pin="PB12" pad="33"/>
<connect gate="G$1" pin="PB13" pad="34"/>
<connect gate="G$1" pin="PB14" pad="35"/>
<connect gate="G$1" pin="PB15" pad="36"/>
<connect gate="G$1" pin="PB2" pad="28"/>
<connect gate="G$1" pin="PB3" pad="55"/>
<connect gate="G$1" pin="PB4" pad="56"/>
<connect gate="G$1" pin="PB5" pad="57"/>
<connect gate="G$1" pin="PB6" pad="58"/>
<connect gate="G$1" pin="PB7" pad="59"/>
<connect gate="G$1" pin="PB8" pad="61"/>
<connect gate="G$1" pin="PB9" pad="62"/>
<connect gate="G$1" pin="PC0" pad="8"/>
<connect gate="G$1" pin="PC1" pad="9"/>
<connect gate="G$1" pin="PC10" pad="51"/>
<connect gate="G$1" pin="PC11" pad="52"/>
<connect gate="G$1" pin="PC12" pad="53"/>
<connect gate="G$1" pin="PC13" pad="2"/>
<connect gate="G$1" pin="PC14" pad="3"/>
<connect gate="G$1" pin="PC15" pad="4"/>
<connect gate="G$1" pin="PC2" pad="10"/>
<connect gate="G$1" pin="PC3" pad="11"/>
<connect gate="G$1" pin="PC4" pad="24"/>
<connect gate="G$1" pin="PC5" pad="25"/>
<connect gate="G$1" pin="PC6" pad="37"/>
<connect gate="G$1" pin="PC7" pad="38"/>
<connect gate="G$1" pin="PC8" pad="39"/>
<connect gate="G$1" pin="PC9" pad="40"/>
<connect gate="G$1" pin="PD2" pad="54"/>
<connect gate="G$1" pin="PH0" pad="5"/>
<connect gate="G$1" pin="PH1" pad="6"/>
<connect gate="G$1" pin="VBAT" pad="1"/>
<connect gate="G$1" pin="VCAP_1" pad="31"/>
<connect gate="G$1" pin="VCAP_2" pad="47"/>
<connect gate="G$1" pin="VDDA" pad="13"/>
<connect gate="G$1" pin="VDD_1" pad="19"/>
<connect gate="G$1" pin="VDD_2" pad="32"/>
<connect gate="G$1" pin="VDD_3" pad="48"/>
<connect gate="G$1" pin="VDD_4" pad="64"/>
<connect gate="G$1" pin="VSSA" pad="12"/>
<connect gate="G$1" pin="VSS_1" pad="18"/>
<connect gate="G$1" pin="VSS_2" pad="63"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8852219/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="PS1" library="SamacSys_Parts" deviceset="TPS82085SILR" device="SON65P280X300X133-9T" package3d_urn="urn:adsk.eagle:package:8852109/1"/>
<part name="IC1" library="SamacSys_Parts" deviceset="STM32F405RGT6" device="LQFP64" package3d_urn="urn:adsk.eagle:package:8852219/1"/>
</parts>
<sheets>
<sheet>
<description>power supply</description>
<plain>
</plain>
<instances>
<instance part="PS1" gate="G$1" x="45.72" y="60.96" smashed="yes">
<attribute name="NAME" x="72.39" y="68.58" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="72.39" y="66.04" size="1.778" layer="96" align="center-left"/>
</instance>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
<sheet>
<description>mcu</description>
<plain>
</plain>
<instances>
<instance part="IC1" gate="G$1" x="55.88" y="73.66" smashed="yes">
<attribute name="NAME" x="105.41" y="91.44" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="105.41" y="88.9" size="1.778" layer="96" align="center-left"/>
</instance>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
<sheet>
<description>gyro+accel</description>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
<sheet>
<description>motor controll</description>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
<sheet>
<description>encoder</description>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
<sheet>
<description>IRs and PTs</description>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
<sheet>
<description>wifi modul</description>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
