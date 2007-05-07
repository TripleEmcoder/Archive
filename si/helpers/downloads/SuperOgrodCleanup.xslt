<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <!--<xsl:output method="xml" indent="yes" />-->
  <!--<xsl:strip-space elements="*" />-->

  <xsl:template match="plant">
    <plant name="{@name}">
      <property name="grupa" value="{@group}" />
      <xsl:apply-templates select="property" />

      <xsl:variable name="this" select="." />
      <xsl:for-each select="//plant[2]/property">
        <xsl:variable name="name" select="@name" />
        <xsl:if test="not($this/property[@name=$name])">
          <property name="{@name}" value="nieokreślone" />
        </xsl:if>
      </xsl:for-each>
    </plant>
  </xsl:template>

  <xsl:template match="*|@*">
    <xsl:copy>
      <xsl:apply-templates select="*|@*" />
    </xsl:copy>
  </xsl:template>

</xsl:stylesheet>