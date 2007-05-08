<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <!--<xsl:output method="xml" indent="yes" />-->
  <!--<xsl:strip-space elements="*" />-->
  
  <xsl:template match="/">
    <encyclopedia>
      <xsl:apply-templates select="//td[@bgcolor='#f0f0f0']/a[not(img)]">
        <xsl:sort select="." />
        <xsl:sort select="position()" />
      </xsl:apply-templates>
    </encyclopedia>
  </xsl:template>

  <xsl:template match="a">
    <xsl:variable name="quot" select="'&quot;'" />
    <xsl:variable name="apos" select='"&apos;"' />
    <plant name="{translate(., $quot, $apos)}" path="{@href}" group="{preceding::b[1]}" />
  </xsl:template>
  
</xsl:stylesheet>