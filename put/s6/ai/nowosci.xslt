<?xml version="1.0" encoding="utf-8"?>

<xsl:stylesheet version="1.0"
                xmlns:ai="urn:inf75922-s6-ai"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:strip-space elements="*" />
  
  <xsl:output method="html"
              doctype-public="-//W3C//DTD HTML 4.01//EN"
              doctype-system="http://www.w3.org/TR/html4/strict.dtd"
              indent="yes" />

  <xsl:template match="/">
    <html>
      <body>
        <table>
          <xsl:apply-templates />
        </table>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="ai:film">
    <tr>
      <td>
        <p>
          <xsl:value-of select="ai:opis" />
        </p>
        (<xsl:value-of select="ancestor::ai:dystrybutor/@nazwa"/>)
      </td>
      <td>
        <h1>
          <xsl:value-of select="ai:tytul" />
          (<xsl:value-of select="ai:tytul_oryginalny" />)
        </h1>
        <h3>
          <xsl:value-of select="ai:rezyser" />
        </h3>
        <xsl:apply-templates select="ai:obsada" />
      </td>
    </tr>
  </xsl:template>

  <xsl:template match="ai:obsada">
    <h3>Obsada:</h3>
    <ul>
      <xsl:apply-templates select="ai:rola" />
    </ul>
  </xsl:template>

  <xsl:template match="ai:rola">
    <li>
      <xsl:value-of select="ai:nazwa"/>: <xsl:value-of select="ai:aktor"/>
    </li>
  </xsl:template>
</xsl:stylesheet>
