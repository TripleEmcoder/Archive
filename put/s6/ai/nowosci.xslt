<?xml version="1.0" encoding="utf-8"?>

<xsl:stylesheet version="1.0"
                xmlns="http://www.w3.org/1999/xhtml"
                xmlns:ai="urn:inf75922-s6-ai"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:strip-space elements="*" />

  <xsl:output method="xml"
              doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN"
              doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"
              indent="yes" />

  <xsl:template match="/">
    <html>
      <head>
        <title>Nowości</title>
        <link rel="stylesheet" href="style.css" />
      </head>
      <body>
        <div id='naglowek'>
          <a href='lista.php'>Lista</a>
          <a href='koszyk.php'>Koszyk</a>
          <a href='problem.php'>Problem</a>
          <a href='nowosci.xml'>Nowości</a>
        </div>
        <div id='tresc'>
          <table>
            <xsl:apply-templates />
          </table>
        </div>
        <div id='stopka'>
          <a href="http://validator.w3.org/check?uri=referer">
            <img src="http://www.w3.org/Icons/valid-xhtml10" alt="Valid XHTML 1.0 Strict" height="31" width="88" />
          </a>
          <a href="http://jigsaw.w3.org/css-validator/check/referer">
            <img src="http://www.w3.org/Icons/valid-css2" alt="Valid HTML 4.01" height="31" width="88" />
          </a>
        </div>
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
