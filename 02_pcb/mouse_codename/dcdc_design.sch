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
<fusionteam huburn="a.cGVyc29uYWw6dWUyOWUzYzUy" projecturn="a.cGVyc29uYWw6dWUyOWUzYzUyIzIwMTkwMjExMTc1NjcyODUx" folderUrn="urn:adsk.wipprod:fs.folder:co.RxKyY8RMSu-esEzEsS3Adw" urn="urn:adsk.wipprod:dm.lineage:u1t83sbkQv2DnDsKVROaCA"  versionUrn="urn:adsk.wipprod:fs.file:vf.u1t83sbkQv2DnDsKVROaCA?version=1" camFileUrn="" camFileVersionUrn="" lastpublishedchangeguid="389edd94-3b18-0744-bd0a-8f412638b8ad"/>
<libraries>
<library name="parts" urn="urn:adsk.eagle:library:8879268">
<packages>
<package name="B3U-1000P" urn="urn:adsk.eagle:footprint:8879274/2" library_version="3" library_locally_modified="yes">
<description>&lt;b&gt;B3U-1000P(M)&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="1.7" y="0" dx="1.7" dy="0.8" layer="1" rot="R90"/>
<smd name="2" x="-1.7" y="0" dx="1.7" dy="0.8" layer="1" rot="R90"/>
<text x="-0.08" y="2.207" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="-0.08" y="-2.111" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-1.5" y1="1.25" x2="1.5" y2="1.25" width="0.2" layer="51"/>
<wire x1="1.5" y1="1.25" x2="1.5" y2="-1.25" width="0.2" layer="51"/>
<wire x1="1.5" y1="-1.25" x2="-1.5" y2="-1.25" width="0.2" layer="51"/>
<wire x1="-1.5" y1="-1.25" x2="-1.5" y2="1.25" width="0.2" layer="51"/>
<wire x1="-1.5" y1="1.25" x2="1.5" y2="1.25" width="0.2" layer="21"/>
<wire x1="-1.5" y1="-1.25" x2="1.5" y2="-1.25" width="0.2" layer="21"/>
<circle x="2.395" y="0.971" radius="0.1" width="0.2" layer="25"/>
</package>
<package name="B3U-3000P" urn="urn:adsk.eagle:footprint:8879467/2" library_version="3" library_locally_modified="yes">
<description>&lt;b&gt;B3U-1000P(M)&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="1.7" y="0" dx="1.7" dy="0.8" layer="1" rot="R90"/>
<smd name="2" x="-1.7" y="0" dx="1.7" dy="0.8" layer="1" rot="R90"/>
<text x="-0.461" y="2.207" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="-0.588" y="-2.111" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-1.5" y1="1.25" x2="1.5" y2="1.25" width="0.2" layer="51"/>
<wire x1="1.5" y1="1.25" x2="1.5" y2="-1.25" width="0.2" layer="51"/>
<wire x1="1.5" y1="-1.25" x2="-1.5" y2="-1.25" width="0.2" layer="51"/>
<wire x1="-1.5" y1="-1.25" x2="-1.5" y2="1.25" width="0.2" layer="51"/>
<wire x1="-1.5" y1="1.25" x2="1.5" y2="1.25" width="0.2" layer="21"/>
<wire x1="-1.5" y1="-1.25" x2="1.5" y2="-1.25" width="0.2" layer="21"/>
<circle x="2.395" y="0.971" radius="0.1" width="0.2" layer="25"/>
</package>
<package name="QFP50P1200X1200X160-64N" urn="urn:adsk.eagle:footprint:8879271/2" library_version="4">
<description>&lt;b&gt;LQFP64&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="-5.75" y="3.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="2" x="-5.75" y="3.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="3" x="-5.75" y="2.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="4" x="-5.75" y="2.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="5" x="-5.75" y="1.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="6" x="-5.75" y="1.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="7" x="-5.75" y="0.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="8" x="-5.75" y="0.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="9" x="-5.75" y="-0.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="10" x="-5.75" y="-0.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="11" x="-5.75" y="-1.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="12" x="-5.75" y="-1.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="13" x="-5.75" y="-2.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="14" x="-5.75" y="-2.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="15" x="-5.75" y="-3.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="16" x="-5.75" y="-3.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="17" x="-3.75" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="18" x="-3.25" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="19" x="-2.75" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="20" x="-2.25" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="21" x="-1.75" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="22" x="-1.25" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="23" x="-0.75" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="24" x="-0.25" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="25" x="0.25" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="26" x="0.75" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="27" x="1.25" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="28" x="1.75" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="29" x="2.25" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="30" x="2.75" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="31" x="3.25" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="32" x="3.75" y="-5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="33" x="5.75" y="-3.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="34" x="5.75" y="-3.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="35" x="5.75" y="-2.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="36" x="5.75" y="-2.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="37" x="5.75" y="-1.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="38" x="5.75" y="-1.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="39" x="5.75" y="-0.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="40" x="5.75" y="-0.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="41" x="5.75" y="0.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="42" x="5.75" y="0.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="43" x="5.75" y="1.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="44" x="5.75" y="1.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="45" x="5.75" y="2.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="46" x="5.75" y="2.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="47" x="5.75" y="3.25" dx="1.45" dy="0.3" layer="1"/>
<smd name="48" x="5.75" y="3.75" dx="1.45" dy="0.3" layer="1"/>
<smd name="49" x="3.75" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="50" x="3.25" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="51" x="2.75" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="52" x="2.25" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="53" x="1.75" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="54" x="1.25" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="55" x="0.75" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="56" x="0.25" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="57" x="-0.25" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="58" x="-0.75" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="59" x="-1.25" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="60" x="-1.75" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="61" x="-2.25" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="62" x="-2.75" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="63" x="-3.25" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<smd name="64" x="-3.75" y="5.75" dx="1.45" dy="0.3" layer="1" rot="R90"/>
<text x="0" y="1.27" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="-1.27" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-6.725" y1="6.725" x2="6.725" y2="6.725" width="0.05" layer="51"/>
<wire x1="6.725" y1="6.725" x2="6.725" y2="-6.725" width="0.05" layer="51"/>
<wire x1="6.725" y1="-6.725" x2="-6.725" y2="-6.725" width="0.05" layer="51"/>
<wire x1="-6.725" y1="-6.725" x2="-6.725" y2="6.725" width="0.05" layer="51"/>
<wire x1="-5" y1="5" x2="5" y2="5" width="0.1" layer="51"/>
<wire x1="5" y1="5" x2="5" y2="-5" width="0.1" layer="51"/>
<wire x1="5" y1="-5" x2="-5" y2="-5" width="0.1" layer="51"/>
<wire x1="-5" y1="-5" x2="-5" y2="5" width="0.1" layer="51"/>
<wire x1="-5" y1="4.5" x2="-4.5" y2="5" width="0.1" layer="51"/>
<wire x1="-4.675" y1="4.675" x2="4.675" y2="4.675" width="0.2" layer="21"/>
<wire x1="4.675" y1="4.675" x2="4.675" y2="-4.675" width="0.2" layer="21"/>
<wire x1="4.675" y1="-4.675" x2="-4.675" y2="-4.675" width="0.2" layer="21"/>
<wire x1="-4.675" y1="-4.675" x2="-4.675" y2="4.675" width="0.2" layer="21"/>
<circle x="-3.685" y="3.738" radius="0.125" width="0.25" layer="25"/>
</package>
<package name="TPS82085" urn="urn:adsk.eagle:footprint:8879270/2" library_version="4">
<description>&lt;b&gt;SIL0008C_1&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="-1.1" y="0.975" dx="0.6" dy="0.4" layer="1"/>
<smd name="2" x="-1.1" y="0.325" dx="0.6" dy="0.4" layer="1"/>
<smd name="3" x="-1.1" y="-0.325" dx="0.6" dy="0.4" layer="1"/>
<smd name="4" x="-1.1" y="-0.975" dx="0.6" dy="0.4" layer="1"/>
<smd name="5" x="1.1" y="-0.975" dx="0.6" dy="0.4" layer="1"/>
<smd name="6" x="1.1" y="-0.325" dx="0.6" dy="0.4" layer="1"/>
<smd name="7" x="1.1" y="0.325" dx="0.6" dy="0.4" layer="1"/>
<smd name="8" x="1.1" y="0.975" dx="0.6" dy="0.4" layer="1"/>
<smd name="9" x="0" y="0" dx="2" dy="1.2" layer="1" rot="R90"/>
<text x="0" y="2.54" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="-2.54" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-1.4" y1="1.5" x2="1.4" y2="1.5" width="0.2" layer="51"/>
<wire x1="1.4" y1="1.5" x2="1.4" y2="-1.5" width="0.2" layer="51"/>
<wire x1="1.4" y1="-1.5" x2="-1.4" y2="-1.5" width="0.2" layer="51"/>
<wire x1="-1.4" y1="-1.5" x2="-1.4" y2="1.5" width="0.2" layer="51"/>
<wire x1="-2.4" y1="2.5" x2="2.4" y2="2.5" width="0.1" layer="51"/>
<wire x1="2.4" y1="2.5" x2="2.4" y2="-2.5" width="0.1" layer="51"/>
<wire x1="2.4" y1="-2.5" x2="-2.4" y2="-2.5" width="0.1" layer="51"/>
<wire x1="-2.4" y1="-2.5" x2="-2.4" y2="2.5" width="0.1" layer="51"/>
<wire x1="-1.4" y1="1.5" x2="1.4" y2="1.5" width="0.1" layer="21"/>
<wire x1="1.4" y1="-1.5" x2="-1.4" y2="-1.5" width="0.1" layer="21"/>
<wire x1="-1.805" y1="0.975" x2="-1.747" y2="0.975" width="0.058" layer="21" curve="180"/>
<wire x1="-1.747" y1="0.975" x2="-1.805" y2="0.975" width="0.058" layer="21" curve="180"/>
<dimension x1="-1.4" y1="1.5" x2="1.4" y2="1.5" x3="0" y3="3.805" textsize="1.27" layer="20" dtype="diameter"/>
<dimension x1="-1.4" y1="1.5" x2="-0.796" y2="1.174" x3="-1.098" y3="6.569" textsize="1.27" layer="20" dtype="horizontal"/>
<dimension x1="-1.401" y1="0.774" x2="-1.399" y2="1.17" x3="-7.458" y3="0.972" textsize="1.27" layer="20" dtype="vertical"/>
</package>
<package name="DRV8836" urn="urn:adsk.eagle:footprint:8872087/3" library_version="4">
<description>16-QFN, 0.50 mm pitch, 2.00 X 3.00 X 0.80 mm body, 0.70 X 1.60 mm thermal pad
&lt;p&gt;16-pin QFN package with 0.50 mm pitch with body size 2.00 X 3.00 X 0.80 mm and thermal pad size 0.70 X 1.60 mm&lt;/p&gt;</description>
<circle x="-1.524" y="1.927" radius="0.25" width="0" layer="21"/>
<wire x1="1.05" y1="1.639" x2="0.639" y2="1.639" width="0.12" layer="21"/>
<wire x1="1.05" y1="-1.639" x2="0.639" y2="-1.639" width="0.12" layer="21"/>
<wire x1="-1.05" y1="-1.639" x2="-0.639" y2="-1.639" width="0.12" layer="21"/>
<wire x1="-1.05" y1="1.639" x2="-0.639" y2="1.639" width="0.12" layer="21"/>
<wire x1="-1.05" y1="-1.55" x2="-1.05" y2="1.55" width="0.12" layer="51"/>
<wire x1="-1.05" y1="1.55" x2="1.05" y2="1.55" width="0.12" layer="51"/>
<wire x1="1.05" y1="1.55" x2="1.05" y2="-1.55" width="0.12" layer="51"/>
<wire x1="1.05" y1="-1.55" x2="-1.05" y2="-1.55" width="0.12" layer="51"/>
<smd name="14" x="0.25" y="1.4956" dx="0.738" dy="0.27" layer="1" rot="R270"/>
<smd name="15" x="-0.25" y="1.4956" dx="0.738" dy="0.27" layer="1" rot="R270"/>
<smd name="1" x="-0.9956" y="1.25" dx="0.738" dy="0.27" layer="1"/>
<smd name="2" x="-0.9956" y="0.75" dx="0.738" dy="0.27" layer="1"/>
<smd name="3" x="-0.9956" y="0.25" dx="0.738" dy="0.27" layer="1"/>
<smd name="4" x="-0.9956" y="-0.25" dx="0.738" dy="0.27" layer="1"/>
<smd name="5" x="-0.9956" y="-0.75" dx="0.738" dy="0.27" layer="1"/>
<smd name="6" x="-0.9956" y="-1.25" dx="0.738" dy="0.27" layer="1"/>
<smd name="16" x="-0.25" y="-1.4956" dx="0.738" dy="0.27" layer="1" rot="R270"/>
<smd name="17" x="0.25" y="-1.4956" dx="0.738" dy="0.27" layer="1" rot="R270"/>
<smd name="7" x="0.9956" y="-1.25" dx="0.738" dy="0.27" layer="1"/>
<smd name="8" x="0.9956" y="-0.75" dx="0.738" dy="0.27" layer="1"/>
<smd name="9" x="0.9956" y="-0.25" dx="0.738" dy="0.27" layer="1"/>
<smd name="10" x="0.9956" y="0.25" dx="0.738" dy="0.27" layer="1"/>
<smd name="11" x="0.9956" y="0.75" dx="0.738" dy="0.27" layer="1"/>
<smd name="12" x="0.9956" y="1.25" dx="0.738" dy="0.27" layer="1"/>
<smd name="13" x="0" y="0" dx="1.6" dy="0.7" layer="1" rot="R270" thermals="no"/>
<text x="0" y="2.5076" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<text x="0" y="-2.1266" size="1.27" layer="27" align="top-center">&gt;VALUE</text>
</package>
<package name="MPU6050" urn="urn:adsk.eagle:footprint:8879272/2" library_version="4">
<description>&lt;b&gt;MPU-6050-5&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="-1.975" y="1.25" dx="0.85" dy="0.35" layer="1"/>
<smd name="2" x="-1.975" y="0.75" dx="0.85" dy="0.35" layer="1"/>
<smd name="3" x="-1.975" y="0.25" dx="0.85" dy="0.35" layer="1"/>
<smd name="4" x="-1.975" y="-0.25" dx="0.85" dy="0.35" layer="1"/>
<smd name="5" x="-1.975" y="-0.75" dx="0.85" dy="0.35" layer="1"/>
<smd name="6" x="-1.975" y="-1.25" dx="0.85" dy="0.35" layer="1"/>
<smd name="7" x="1.975" y="-1.25" dx="0.85" dy="0.35" layer="1"/>
<smd name="8" x="1.975" y="-0.75" dx="0.85" dy="0.35" layer="1"/>
<smd name="9" x="1.975" y="-0.25" dx="0.85" dy="0.35" layer="1"/>
<smd name="10" x="1.975" y="0.25" dx="0.85" dy="0.35" layer="1"/>
<smd name="11" x="1.975" y="0.75" dx="0.85" dy="0.35" layer="1"/>
<smd name="12" x="1.975" y="1.25" dx="0.85" dy="0.35" layer="1"/>
<smd name="13" x="-0.25" y="-1.975" dx="0.85" dy="0.35" layer="1" rot="R90"/>
<smd name="14" x="-0.75" y="-1.975" dx="0.85" dy="0.35" layer="1" rot="R90"/>
<smd name="15" x="-1.25" y="-1.975" dx="0.85" dy="0.35" layer="1" rot="R90"/>
<smd name="16" x="0.25" y="-1.975" dx="0.85" dy="0.35" layer="1" rot="R90"/>
<smd name="17" x="0.75" y="-1.975" dx="0.85" dy="0.35" layer="1" rot="R90"/>
<smd name="18" x="1.25" y="-1.975" dx="0.85" dy="0.35" layer="1" rot="R90"/>
<smd name="19" x="1.25" y="1.975" dx="0.85" dy="0.35" layer="1" rot="R90"/>
<smd name="20" x="0.75" y="1.975" dx="0.85" dy="0.35" layer="1" rot="R90"/>
<smd name="21" x="0.25" y="1.975" dx="0.85" dy="0.35" layer="1" rot="R90"/>
<smd name="22" x="-0.25" y="1.975" dx="0.85" dy="0.35" layer="1" rot="R90"/>
<smd name="23" x="-0.75" y="1.975" dx="0.85" dy="0.35" layer="1" rot="R90"/>
<smd name="24" x="-1.25" y="1.975" dx="0.85" dy="0.35" layer="1" rot="R90"/>
<smd name="25" x="0" y="0" dx="2.7" dy="2.6" layer="1"/>
<text x="0" y="3.302" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="-3.175" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-2" y1="2" x2="2" y2="2" width="0.2" layer="51"/>
<wire x1="2" y1="2" x2="2" y2="-2" width="0.2" layer="51"/>
<wire x1="2" y1="-2" x2="-2" y2="-2" width="0.2" layer="51"/>
<wire x1="-2" y1="-2" x2="-2" y2="2" width="0.2" layer="51"/>
<wire x1="-3.4" y1="3.4" x2="3.4" y2="3.4" width="0.1" layer="51"/>
<wire x1="3.4" y1="3.4" x2="3.4" y2="-3.4" width="0.1" layer="51"/>
<wire x1="3.4" y1="-3.4" x2="-3.4" y2="-3.4" width="0.1" layer="51"/>
<wire x1="-3.4" y1="-3.4" x2="-3.4" y2="3.4" width="0.1" layer="51"/>
<wire x1="-2" y1="-1.6" x2="-2" y2="-1.975" width="0.1" layer="21"/>
<wire x1="-2" y1="-1.975" x2="-1.6" y2="-1.975" width="0.1" layer="21"/>
<wire x1="1.6" y1="-2" x2="1.975" y2="-2" width="0.1" layer="21"/>
<wire x1="1.975" y1="-2" x2="2" y2="-1.975" width="0.1" layer="21"/>
<wire x1="2" y1="-1.975" x2="2" y2="-1.6" width="0.1" layer="21"/>
<wire x1="1.6" y1="2" x2="2" y2="2" width="0.1" layer="21"/>
<wire x1="2" y1="2" x2="2" y2="1.6" width="0.1" layer="21"/>
<wire x1="-1.6" y1="2" x2="-2" y2="2" width="0.1" layer="21"/>
<wire x1="-2" y1="2" x2="-2" y2="1.6" width="0.1" layer="21"/>
<wire x1="-2.419" y1="2.316" x2="-2.419" y2="2.216" width="0.1" layer="21" curve="180"/>
<wire x1="-2.419" y1="2.216" x2="-2.419" y2="2.316" width="0.1" layer="21" curve="180"/>
</package>
</packages>
<packages3d>
<package3d name="B3U-1000P" urn="urn:adsk.eagle:package:8879289/3" type="model" library_version="3" library_locally_modified="yes">
<description>&lt;b&gt;B3U-1000P(M)&lt;/b&gt;&lt;br&gt;</description>
<packageinstances>
<packageinstance name="B3U-1000P"/>
</packageinstances>
</package3d>
<package3d name="B3U-3000P" urn="urn:adsk.eagle:package:8879469/3" type="model" library_version="3" library_locally_modified="yes">
<description>&lt;b&gt;B3U-1000P(M)&lt;/b&gt;&lt;br&gt;</description>
<packageinstances>
<packageinstance name="B3U-3000P"/>
</packageinstances>
</package3d>
<package3d name="QFP50P1200X1200X160-64N" urn="urn:adsk.eagle:package:8879286/3" type="model" library_version="4">
<description>&lt;b&gt;LQFP64&lt;/b&gt;&lt;br&gt;</description>
<packageinstances>
<packageinstance name="QFP50P1200X1200X160-64N"/>
</packageinstances>
</package3d>
<package3d name="TPS82085SILR" urn="urn:adsk.eagle:package:8879285/3" type="model" library_version="4">
<description>&lt;b&gt;SIL0008C_1&lt;/b&gt;&lt;br&gt;</description>
<packageinstances>
<packageinstance name="TPS82085"/>
</packageinstances>
</package3d>
<package3d name="QFN50P300X200X80-17T160X70" urn="urn:adsk.eagle:package:8872076/3" type="model" library_version="4">
<description>16-QFN, 0.50 mm pitch, 2.00 X 3.00 X 0.80 mm body, 0.70 X 1.60 mm thermal pad
&lt;p&gt;16-pin QFN package with 0.50 mm pitch with body size 2.00 X 3.00 X 0.80 mm and thermal pad size 0.70 X 1.60 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="DRV8836"/>
</packageinstances>
</package3d>
<package3d name="MPU6050" urn="urn:adsk.eagle:package:8879287/3" type="model" library_version="4">
<description>&lt;b&gt;MPU-6050-5&lt;/b&gt;&lt;br&gt;</description>
<packageinstances>
<packageinstance name="MPU6050"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="B3U-1000P" urn="urn:adsk.eagle:symbol:8879282/1" library_version="3" library_locally_modified="yes">
<wire x1="5.08" y1="2.54" x2="15.24" y2="2.54" width="0.254" layer="94"/>
<wire x1="15.24" y1="-2.54" x2="15.24" y2="2.54" width="0.254" layer="94"/>
<wire x1="15.24" y1="-2.54" x2="5.08" y2="-2.54" width="0.254" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-2.54" width="0.254" layer="94"/>
<text x="16.51" y="7.62" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="16.51" y="5.08" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="K" x="0" y="0" length="middle"/>
<pin name="A" x="20.32" y="0" length="middle" rot="R180"/>
</symbol>
<symbol name="B3U-3000P" urn="urn:adsk.eagle:symbol:8879281/1" library_version="3" library_locally_modified="yes">
<wire x1="5.08" y1="2.54" x2="15.24" y2="2.54" width="0.254" layer="94"/>
<wire x1="15.24" y1="-2.54" x2="15.24" y2="2.54" width="0.254" layer="94"/>
<wire x1="15.24" y1="-2.54" x2="5.08" y2="-2.54" width="0.254" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-2.54" width="0.254" layer="94"/>
<text x="16.51" y="7.62" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="16.51" y="5.08" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="1" x="0" y="0" length="middle"/>
<pin name="2" x="20.32" y="0" length="middle" rot="R180"/>
</symbol>
<symbol name="STM32F405RG" urn="urn:adsk.eagle:symbol:8879278/2" library_version="4">
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
<symbol name="TPS82085" urn="urn:adsk.eagle:symbol:8879277/2" library_version="4">
<wire x1="5.08" y1="2.54" x2="25.4" y2="2.54" width="0.254" layer="94"/>
<wire x1="25.4" y1="-12.7" x2="25.4" y2="2.54" width="0.254" layer="94"/>
<wire x1="25.4" y1="-12.7" x2="5.08" y2="-12.7" width="0.254" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-12.7" width="0.254" layer="94"/>
<text x="26.67" y="7.62" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="26.67" y="5.08" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="EN" x="0" y="0" length="middle"/>
<pin name="PG" x="0" y="-2.54" length="middle"/>
<pin name="VIN_1" x="0" y="-5.08" length="middle"/>
<pin name="VIN_2" x="0" y="-7.62" length="middle"/>
<pin name="GND_1" x="0" y="-10.16" length="middle"/>
<pin name="GND_2" x="30.48" y="0" length="middle" rot="R180"/>
<pin name="FB" x="30.48" y="-2.54" length="middle" rot="R180"/>
<pin name="VOUT" x="30.48" y="-5.08" length="middle" rot="R180"/>
<pin name="EP" x="30.48" y="-7.62" length="middle" rot="R180"/>
</symbol>
<symbol name="DRV8836DSSR" urn="urn:adsk.eagle:symbol:8879280/1" library_version="3" library_locally_modified="yes">
<wire x1="5.08" y1="2.54" x2="35.56" y2="2.54" width="0.254" layer="94"/>
<wire x1="35.56" y1="-20.32" x2="35.56" y2="2.54" width="0.254" layer="94"/>
<wire x1="35.56" y1="-20.32" x2="5.08" y2="-20.32" width="0.254" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-20.32" width="0.254" layer="94"/>
<text x="36.83" y="7.62" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="36.83" y="5.08" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="VCC" x="0" y="0" length="middle"/>
<pin name="AOUT1" x="0" y="-2.54" length="middle"/>
<pin name="AOUT2" x="0" y="-5.08" length="middle"/>
<pin name="BOUT1" x="0" y="-7.62" length="middle"/>
<pin name="BOUT2" x="0" y="-10.16" length="middle"/>
<pin name="GND" x="0" y="-12.7" length="middle"/>
<pin name="EP" x="20.32" y="-25.4" length="middle" rot="R90"/>
<pin name="NSLEEP" x="40.64" y="0" length="middle" rot="R180"/>
<pin name="MODE" x="40.64" y="-2.54" length="middle" rot="R180"/>
<pin name="AIN1_/_APHASE" x="40.64" y="-5.08" length="middle" rot="R180"/>
<pin name="AIN2_/_AENBL" x="40.64" y="-7.62" length="middle" rot="R180"/>
<pin name="BIN1_/_BPHASE" x="40.64" y="-10.16" length="middle" rot="R180"/>
<pin name="BIN2_/_BENBL" x="40.64" y="-12.7" length="middle" rot="R180"/>
</symbol>
<symbol name="MPU-6050" urn="urn:adsk.eagle:symbol:8879279/1" library_version="3" library_locally_modified="yes">
<wire x1="5.08" y1="2.54" x2="27.94" y2="2.54" width="0.254" layer="94"/>
<wire x1="27.94" y1="-33.02" x2="27.94" y2="2.54" width="0.254" layer="94"/>
<wire x1="27.94" y1="-33.02" x2="5.08" y2="-33.02" width="0.254" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-33.02" width="0.254" layer="94"/>
<text x="29.21" y="7.62" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="29.21" y="5.08" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="CLKIN" x="0" y="0" length="middle"/>
<pin name="NC_1" x="0" y="-2.54" length="middle"/>
<pin name="NC_2" x="0" y="-5.08" length="middle"/>
<pin name="NC_3" x="0" y="-7.62" length="middle"/>
<pin name="NC_4" x="0" y="-10.16" length="middle"/>
<pin name="AUX_DA" x="0" y="-12.7" length="middle"/>
<pin name="AUX_CL" x="0" y="-15.24" length="middle"/>
<pin name="VLOGIC" x="0" y="-17.78" length="middle"/>
<pin name="AD0" x="0" y="-20.32" length="middle"/>
<pin name="REGOUT" x="0" y="-22.86" length="middle"/>
<pin name="FSYNC" x="0" y="-25.4" length="middle"/>
<pin name="INT" x="0" y="-27.94" length="middle"/>
<pin name="VDD" x="0" y="-30.48" length="middle"/>
<pin name="NC_5" x="33.02" y="0" length="middle" rot="R180"/>
<pin name="NC_6" x="33.02" y="-2.54" length="middle" rot="R180"/>
<pin name="NC_7" x="33.02" y="-5.08" length="middle" rot="R180"/>
<pin name="NC_8" x="33.02" y="-7.62" length="middle" rot="R180"/>
<pin name="GND" x="33.02" y="-10.16" length="middle" rot="R180"/>
<pin name="RESV_1" x="33.02" y="-12.7" length="middle" rot="R180"/>
<pin name="CPOUT" x="33.02" y="-15.24" length="middle" rot="R180"/>
<pin name="RESV_2" x="33.02" y="-17.78" length="middle" rot="R180"/>
<pin name="RESV_3" x="33.02" y="-20.32" length="middle" rot="R180"/>
<pin name="SCL" x="33.02" y="-22.86" length="middle" rot="R180"/>
<pin name="SDA" x="33.02" y="-25.4" length="middle" rot="R180"/>
<pin name="EP" x="33.02" y="-27.94" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="B3U-1000P" urn="urn:adsk.eagle:component:8879297/2" prefix="S" library_version="3" library_locally_modified="yes">
<description>&lt;b&gt;OMRON ELECTRONIC COMPONENTS - B3U-1000P - SWITCH, SPST-NO, 0.05A, 12V, SMD&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://www.mouser.com/datasheet/2/307/en-b3u-3615.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="B3U-1000P" x="0" y="0"/>
</gates>
<devices>
<device name="" package="B3U-1000P">
<connects>
<connect gate="G$1" pin="A" pad="2"/>
<connect gate="G$1" pin="K" pad="1"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8879289/3"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="OMRON ELECTRONIC COMPONENTS - B3U-1000P - SWITCH, SPST-NO, 0.05A, 12V, SMD" constant="no"/>
<attribute name="HEIGHT" value="mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="Omron Electronics" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="B3U-1000P" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="653-B3U-1000P" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="B3U-3000P" urn="urn:adsk.eagle:component:8879296/3" prefix="S" library_version="3" library_locally_modified="yes">
<description>&lt;b&gt;OMRON ELECTRONIC COMPONENTS - B3U-3000P - TACTILE SWITCH, SIDE ACTUATED, SMD&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://www.mouser.com/datasheet/2/307/en-b3u-3615.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="B3U-3000P" x="0" y="0"/>
</gates>
<devices>
<device name="B3U-3000P" package="B3U-3000P">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8879469/3"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="STM32F405RGT6" urn="urn:adsk.eagle:component:8879293/2" prefix="IC" library_version="4">
<description>&lt;b&gt;MCU 32-Bit, ARM Cortex M4, 1MB Flash STMicroelectronics STM32F405RGT6, 32bit ARM Cortex M4F Microcontroller, 168MHz, 1024 kB Flash, 64-Pin LQFP&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://www.mouser.com/datasheet/2/389/stm32f405rg-956214.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="STM32F405RG" x="0" y="0"/>
</gates>
<devices>
<device name="" package="QFP50P1200X1200X160-64N">
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
<package3dinstance package3d_urn="urn:adsk.eagle:package:8879286/3"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="MCU 32-Bit, ARM Cortex M4, 1MB Flash STMicroelectronics STM32F405RGT6, 32bit ARM Cortex M4F Microcontroller, 168MHz, 1024 kB Flash, 64-Pin LQFP" constant="no"/>
<attribute name="HEIGHT" value="1.6mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="STMicroelectronics" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="STM32F405RGT6" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="511-STM32F405RGT6" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="TPS82085" urn="urn:adsk.eagle:component:8879292/2" prefix="PS" library_version="4">
<description>&lt;b&gt;TEXAS INSTRUMENTS - TPS82085SILR - DC/DC CONV, SYNC BUCK, 2.4MHZ, USIP-8&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://www.ti.com/lit/ds/symlink/tps82084.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="TPS82085" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TPS82085">
<connects>
<connect gate="G$1" pin="EN" pad="1"/>
<connect gate="G$1" pin="EP" pad="9"/>
<connect gate="G$1" pin="FB" pad="7"/>
<connect gate="G$1" pin="GND_1" pad="5"/>
<connect gate="G$1" pin="GND_2" pad="6"/>
<connect gate="G$1" pin="PG" pad="2"/>
<connect gate="G$1" pin="VIN_1" pad="3"/>
<connect gate="G$1" pin="VIN_2" pad="4"/>
<connect gate="G$1" pin="VOUT" pad="8"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8879285/3"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="TEXAS INSTRUMENTS - TPS82085SILR - DC/DC CONV, SYNC BUCK, 2.4MHZ, USIP-8" constant="no"/>
<attribute name="HEIGHT" value="1.33mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="Texas Instruments" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="TPS82085SILR" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="595-TPS82085SILR" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="DRV8836" urn="urn:adsk.eagle:component:8879295/2" prefix="IC" library_version="4">
<description>&lt;b&gt;1.5A Low Voltage Stepper or Single/Dual Brushed DC Motor Driver (PWM or PH/EN Ctrl)&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://www.ti.com/lit/gpn/drv8836"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="DRV8836DSSR" x="0" y="0"/>
</gates>
<devices>
<device name="1" package="DRV8836">
<connects>
<connect gate="G$1" pin="AIN1_/_APHASE" pad="10"/>
<connect gate="G$1" pin="AIN2_/_AENBL" pad="9"/>
<connect gate="G$1" pin="AOUT1" pad="2"/>
<connect gate="G$1" pin="AOUT2" pad="3"/>
<connect gate="G$1" pin="BIN1_/_BPHASE" pad="8"/>
<connect gate="G$1" pin="BIN2_/_BENBL" pad="7"/>
<connect gate="G$1" pin="BOUT1" pad="4"/>
<connect gate="G$1" pin="BOUT2" pad="5"/>
<connect gate="G$1" pin="EP" pad="13 14 15 16 17"/>
<connect gate="G$1" pin="GND" pad="6"/>
<connect gate="G$1" pin="MODE" pad="11"/>
<connect gate="G$1" pin="NSLEEP" pad="12"/>
<connect gate="G$1" pin="VCC" pad="1"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8872076/3"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="1.5A Low Voltage Stepper or Single/Dual Brushed DC Motor Driver (PWM or PH/EN Ctrl)" constant="no"/>
<attribute name="HEIGHT" value="0.8mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="Texas Instruments" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="DRV8836DSSR" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="595-DRV8836DSSR" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="MPU-6050" urn="urn:adsk.eagle:component:8879294/2" prefix="IC" library_version="4">
<description>&lt;b&gt;IMUs - Inertial Measurement Units 6-Axis MEMS MotionTracking  Device with DMP&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="https://www.mouser.mx/datasheet/2/400/MPU-6000-Datasheet1-1112286.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="MPU-6050" x="0" y="0"/>
</gates>
<devices>
<device name="" package="MPU6050">
<connects>
<connect gate="G$1" pin="AD0" pad="9"/>
<connect gate="G$1" pin="AUX_CL" pad="7"/>
<connect gate="G$1" pin="AUX_DA" pad="6"/>
<connect gate="G$1" pin="CLKIN" pad="1"/>
<connect gate="G$1" pin="CPOUT" pad="20"/>
<connect gate="G$1" pin="EP" pad="25"/>
<connect gate="G$1" pin="FSYNC" pad="11"/>
<connect gate="G$1" pin="GND" pad="18"/>
<connect gate="G$1" pin="INT" pad="12"/>
<connect gate="G$1" pin="NC_1" pad="2"/>
<connect gate="G$1" pin="NC_2" pad="3"/>
<connect gate="G$1" pin="NC_3" pad="4"/>
<connect gate="G$1" pin="NC_4" pad="5"/>
<connect gate="G$1" pin="NC_5" pad="14"/>
<connect gate="G$1" pin="NC_6" pad="15"/>
<connect gate="G$1" pin="NC_7" pad="16"/>
<connect gate="G$1" pin="NC_8" pad="17"/>
<connect gate="G$1" pin="REGOUT" pad="10"/>
<connect gate="G$1" pin="RESV_1" pad="19"/>
<connect gate="G$1" pin="RESV_2" pad="21"/>
<connect gate="G$1" pin="RESV_3" pad="22"/>
<connect gate="G$1" pin="SCL" pad="23"/>
<connect gate="G$1" pin="SDA" pad="24"/>
<connect gate="G$1" pin="VDD" pad="13"/>
<connect gate="G$1" pin="VLOGIC" pad="8"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8879287/3"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="IMUs - Inertial Measurement Units 6-Axis MEMS MotionTracking  Device with DMP" constant="no"/>
<attribute name="HEIGHT" value="3mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="TDK" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="MPU-6050" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="410-MPU-6050" constant="no"/>
</technology>
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
<part name="S1" library="parts" library_urn="urn:adsk.eagle:library:8879268" deviceset="B3U-1000P" device="" package3d_urn="urn:adsk.eagle:package:8879289/3"/>
<part name="S2" library="parts" library_urn="urn:adsk.eagle:library:8879268" deviceset="B3U-3000P" device="B3U-3000P" package3d_urn="urn:adsk.eagle:package:8879469/3"/>
<part name="IC1" library="parts" library_urn="urn:adsk.eagle:library:8879268" deviceset="STM32F405RGT6" device="" package3d_urn="urn:adsk.eagle:package:8879286/3"/>
<part name="PS1" library="parts" library_urn="urn:adsk.eagle:library:8879268" deviceset="TPS82085" device="" package3d_urn="urn:adsk.eagle:package:8879285/3"/>
<part name="IC3" library="parts" library_urn="urn:adsk.eagle:library:8879268" deviceset="DRV8836" device="1" package3d_urn="urn:adsk.eagle:package:8872076/3"/>
<part name="IC2" library="parts" library_urn="urn:adsk.eagle:library:8879268" deviceset="MPU-6050" device="" package3d_urn="urn:adsk.eagle:package:8879287/3"/>
</parts>
<sheets>
<sheet>
<description>power supply</description>
<plain>
</plain>
<instances>
<instance part="PS1" gate="G$1" x="20.32" y="55.88" smashed="yes">
<attribute name="NAME" x="46.99" y="63.5" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="46.99" y="60.96" size="1.778" layer="96" align="center-left"/>
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
<instance part="S1" gate="G$1" x="104.14" y="68.58" smashed="yes">
<attribute name="NAME" x="120.65" y="76.2" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="120.65" y="73.66" size="1.778" layer="96" align="center-left"/>
</instance>
<instance part="S2" gate="G$1" x="104.14" y="53.34" smashed="yes">
<attribute name="NAME" x="120.65" y="60.96" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="120.65" y="58.42" size="1.778" layer="96" align="center-left"/>
</instance>
<instance part="IC1" gate="G$1" x="20.32" y="58.42" smashed="yes">
<attribute name="NAME" x="69.85" y="76.2" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="69.85" y="73.66" size="1.778" layer="96" align="center-left"/>
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
<instance part="IC2" gate="G$1" x="17.78" y="45.72" smashed="yes">
<attribute name="NAME" x="46.99" y="53.34" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="46.99" y="50.8" size="1.778" layer="96" align="center-left"/>
</instance>
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
<instance part="IC3" gate="G$1" x="22.86" y="38.1" smashed="yes">
<attribute name="NAME" x="59.69" y="45.72" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="59.69" y="43.18" size="1.778" layer="96" align="center-left"/>
</instance>
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
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
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
