#pragma once

#include <string>
#include <utility>

/// <summary>
/// Handles update functionality: checking for updates online, and downloading
/// new versions of the software.
/// <p>
/// The latest version number of 3RVX can be retrieved from:
/// http://matthew.malensek.net/projects/3RVX/latest_version
/// <p>
/// Versions can be downloaded from:
/// http://matthew.malensek.net/projects/3RVX/3RVX-X.Y.{zip, msi}
/// Where X is the major version, Y is the minor version, and the type of
/// installation is determined by the package extension:
/// <ul>
///   <li>.msi - Installer based version</li>
///   <li>.zip - Portable (non-installer) version</li>
/// </ul>
/// </summary>
class Updater {
public:
    /// <summary>
    /// Determines whether a new version of the program is available online
    /// or not.
    /// </summary>
    static bool NewerVersionAvailable();

    /// <summary>
    /// Retrieves the version number of the main application (3RVX.exe).
    /// </summary>
    static std::pair<int, int> MainAppVersion();

    /// <summary>
    /// Retrieves the version number of the main application (3RVX.exe) as a 
    /// string in the format X.Y (where X is the major version number and Y
    /// is the minor version number).
    /// </summary>
    static std::wstring MainAppVersionString();

    static void DownloadVersion(std::pair<int, int> version);

private:
    /// <summary>
    /// Retrieves the latest version of the program availabile online.
    /// </summary>
    static std::pair<int, int> RemoteVersion();

    /// <summary>
    /// Retrieves the string-based representation of a version number.
    /// </summary>
    static std::wstring VersionToString(std::pair<int, int> version);

    /// <summary>
    /// Retrieves the file name of the specified version of the program stored
    /// on the remote server (example: 3RVX-3.4.msi).
    /// </summary>
    static std::wstring DownloadFileName(std::pair<int, int> version);

private:
    /// <summary>
    /// Specifies the URL to check to determine the latest version online. The
    /// file at this address is a plain text file that contains a single line
    /// with the currently-available version number (example: 3.2).
    /// </summary>
    static const std::wstring LATEST_URL;

    /// <summary>
    /// Specifies the base URL to use when downloading new versions of the
    /// program.
    /// </summary>
    static const std::wstring DOWNLOAD_URL;
};